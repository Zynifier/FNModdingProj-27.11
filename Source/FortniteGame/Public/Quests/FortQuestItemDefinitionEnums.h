// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortQuestItemDefinitionEnums.generated.h"

UENUM(BlueprintType)
enum class EFortQuestRewardType : uint8
{
	/** All rewards are given upon completion */
	BasicRewards = 0,
	/** An additional single reward is selected from the additional rewards upon completion */
	BasicPlusSingleChoice = 1,
};

UENUM(BlueprintType)
enum class EFortQuestType : uint8
{
	/** Default quest type, this blocks progression */
	Task = 0,
	/** A quest that does not block progression, but is otherwise normal */
	Optional = 1,
	/** Regularly recurring quest */
	DailyQuest = 2,
	/** Quest that removes itself after being claimed */
	TransientQuest = 3,
	/** A survivor quest */
	SurvivorQuest = 4,
	/** Self-contained goal that may take a significant amount of time to complete */
	Achievement = 5,
	/** The initial onboarding quests. The player is considered to be in onboarding until all of these quests are complete */
	Onboarding = 6,
	/** Quests that are only relevant in the Athena game mode; these are typically helper quests that aren't directly shown to the user */
	Athena = 7,
	/** Daily athena quests */
	AthenaDailyQuest = 8,
	/** Athena event quest */
	AthenaEvent = 9,
	/** BR Challenge Bundle Quest (e.g., battle pass weekly quest) */
	AthenaChallengeBundleQuest = 10,
	/** BR quest that doesn't belong to any bundle or schedule - typically given by NPCs and will generally have a short life time */
	AthenaLooseQuest = 11,
	/* Includes all quest types above */
	All = 12,
};

UENUM(BlueprintType)
enum class EObjectiveConversationTriggerType : uint8
{
	/** stat equals x amount */
	StatEquals = 0,
	/** stat increased by x amount */
	StatIncreasedby = 1,
	/** stat less than amount by x */
	StatLessThan = 2,
	Max = 3 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EObjectiveStatusUpdateType : uint8
{
	Always = 0,
	OnPercent = 1,
	OnComplete = 2,
	Never = 3,
};

UENUM(BlueprintType)
enum class EQuestEditorGenerateBackendNameReason : uint8
{
	/* Literally does nothing. The backend name will not be touched. */
	NoAction = 0,
	/**
	 * The backend name only built if it's not already set; if already set it is ignored.
	 * The new backend name is set using a unique id specific to the quest asset.
	 */
	OnlyBuildEmpty = 1,
	/**
	 * The backend name is force rebuilt, even if it's already set. 
	 * The new backend name is set using a unique id specific to the quest asset.
	 */
	ForceRebuild = 2,
};

