import datetime, xmlrpclib

wp_url = "http://localhost/wordpress/xmlrpc.php"
wp_username = "admin"
wp_password = "android"
wp_blogid = ""

status_draft = 0
status_published = 1

server = xmlrpclib.ServerProxy(wp_url)
title = "Title with spaces"
content = "Body with lots of <pre>content</pre>"
date_created = xmlrpclib.DateTime(datetime.datetime.strptime("2013-05-29 15:43", "%Y-%m-%d %H:%M"))
categories = ["category"]
tags = ["tag1","tag2"]
data = {'title':title,'description':content,'dateCreated':date_created,'categories': categories, 'mt_keywords': tags}

post_id = server.metaWeblog.newPost(wp_blogid,wp_username,wp_password,data,status_published)
print post_id
