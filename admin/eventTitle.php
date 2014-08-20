<?php

  if(session_id() == "") session_start();

  require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
  require($_SERVER['DOCUMENT_ROOT']."/php_includes/functions.inc");

  $admin = new admin;
  $id = makeSQLSafe($mysqli, $_GET['id']);
  $title = makeSQLSafe($mysqli, $_GET['title']);

  // Find event by id
  $eventQuery = $mysqli->query("SELECT * FROM `events` where `id` = '$id'");
  if($eventQuery->num_rows == 1) {
    $event = $eventQuery->fetch_assoc();
    $eventId = $event['id'];
    // Update category title
    if($admin->updateEventTitle($mysqli, $_GET['id'], $_GET['title'])) {
      $updatedQuery = $mysqli->query("SELECT * FROM `events` where `id` = '$eventId' LIMIT 1");
      $updated = $updatedQuery->fetch_assoc();

      header('Location: /events/' . $updated['category_url']);
      exit;
    } else {
      echo 'Failed to update...';
    }
  } else {
    echo 'No event found...';
  }