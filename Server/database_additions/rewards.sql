CREATE TABLE IF NOT EXISTS `rewards` (
  `uid` varchar(32) NOT NULL,
  `rewards_player` varchar(1024) NOT NULL DEFAULT '[]',
  PRIMARY KEY (`uid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;