-- DB update 2021_01_28_00 -> 2021_01_29_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_01_28_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_01_28_00 2021_01_29_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1610385898427311800'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1610385898427311800');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (48777,7215,48776);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(48777,'spell_item_with_mount_speed'),
(7215,'spell_item_with_mount_speed'),
(48776,'spell_item_with_mount_speed');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
