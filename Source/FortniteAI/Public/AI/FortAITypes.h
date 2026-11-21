// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Blackboard/BlackboardKeyEnums.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "AI/AIHotSpotManagerProxy.h"
#include "FortTeamEnum.h"
#include "FortAITypes.generated.h"

UENUM()
enum class EAIScalableFloatScalingType : int32
{
	Disabled = 0,
	// Will scale the damage based on the absolute damage received by the current target

	ReceivedDamageByTarget = 1,
};

UENUM(BlueprintType)
enum class EAssignmentType : uint8
{
	Invalid = 0 UMETA(Hidden),
	// Uninitialized

	Encounter = 1,
	World = 2,
	Enemy = 3,
	NumAssignmentTypes = 4 UMETA(Hidden),
};

UENUM()
enum class EBuildingFloorRailing : uint8
{
	None = 0,
	Balcony = 1,
};

UENUM()
namespace EBuildingStairsRailing
{
	enum Type
	{
		None = 0 UMETA(Tooltip="No railings, all dropdown links have default cost"),
		Partial = 1 UMETA(Tooltip="Some railings (e.g. on one side), this is most common setting"),
		Full = 2 UMETA(Tooltip="Railings everywhere, all dropdown links are smashable"),
	};
}

UENUM()
namespace EBuildingWallArea
{
	enum Type
	{
		Regular = 0 UMETA(Tooltip="Regular wall, use EditModePatternData and NavAreaOverride."),
		Flat = 1 UMETA(Tooltip="It's supposed to be a flat surface with navmesh on top."),
		Special = 2 UMETA(Tooltip="Use convex collisions to generate 2D area."),
	};
}

UENUM(BlueprintType)
enum class EFortAILODLevel : uint8
{
	Invalid = 0,
	MIN = 0 UMETA(Hidden),
	Dormant = 1,
	// reserved for dormant or sleeping NPCs. Its assumed in some code that there won't be lower value EFortAILODLevel's than this

	BelowLower = 2,
	// NPC's that are far from the player and not visible, this bucket has an unlimited number of NPC's

	Lower = 3,
	// NPC's that are barely if at all visible, this is a large bucket of NPC's

	AboveLower = 4,
	// many of these NPC's will be visible but it will be harder to ascertain how precise their simulations are, some NPC's in this group could be not 'that' far behind a player.

	BelowNormal = 5,
	// The same as Normal but NPC's a bit further away, many of these NPC's will be easily visible or fairly close behind the player

	Normal = 6,
	// NPC's either very close or close and in the players view

	AboveNormal = 7,
	// NPC's that are either targeted by or very very close to and in a narrow viewcode to the player

	MAX = 8 UMETA(Hidden),
};

UENUM()
enum class EFortHotSpotDirection : uint8
{
	PositiveX = 0,
	NegativeX = 1,
	PositiveY = 2,
	NegativeY = 3,
	PositiveZ = 4,
	NegativeZ = 5,
	Any = 6 UMETA(Hidden),
};

UENUM()
enum class EFortHotSpotPreview : uint8
{
	None = 0,
	Smashing = 1,
	Shooting = 2,
};

UENUM()
enum class EFortHotSpotSlot : uint8
{
	Melee = 0,
	MeleeHuge = 1,
	Ranged = 2,
	None = 3,
};

UENUM()
enum class EFortPartialPathUsage : uint8
{
	Always = 0,
	OnlyGoalsOnDestructible = 1,
	Never = 2,
};

UENUM()
enum class EHotspotTypeConfigMode : uint8
{
	// always add ExtraTypeConfig slots

	AlwaysAdd = 0,
	// add ExtraTypeConfig slots of type X when config doesn't define any slots of type X

	WhenNotDefined = 1,
	// add ExtraTypeConfig slots of type X when none slots of type X were valid (not defined / not projected / not in range)

	WhenNotValid = 2,
};

UENUM(BlueprintType)
enum class ENavigationObstacleOverride : uint8
{
	UseMeshSettings = 0,
	ForceEnabled = 1,
	ForceDisabled = 2,
	/** Will not use the NavModifier export flow, and will export the component geometry directly */
	ExportAsPrimitive = 3,
};

UENUM()
namespace ETargetDistanceComparisonType
{
	enum Type
	{
		TwoDimensions = 0 UMETA(DisplayName="2-D"),
		ThreeDimensions = 1 UMETA(DisplayName="3-D"),
		CollisionHalfHeightMultiplier = 2 UMETA(DisplayName="Collision Half Height Multiplier"),
	};
}

UENUM()
enum class ETeleportReason : uint8
{
	AgentNotOnNavmesh = 0,
	AgentDestinationNotOnNavMesh = 1,
	AgentStuckInRepetitivePartialPaths = 2,
	AgentBlocked = 3,
	Unknown = 4,
};

USTRUCT()
struct FAIHotSpotUseInfo : public FAIHotSpotSlotInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FAIScalableFloat
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Configuration")
	FScalableFloat ScalableFloat;

	UPROPERTY(EditAnywhere, Category="Configuration")
	EAIScalableFloatScalingType ScalingType;

};

USTRUCT()
struct FBuildingActorNavArea
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Area")
	int32 AreaBits;

};

USTRUCT()
struct FDistanceToTargetComparison
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Condition")
	bool bUseOverriddenValue;

	UPROPERTY(EditAnywhere, Category="Condition", meta=(EditCondition="bUseOverriddenValue"))
	float OverriddenValue;

	UPROPERTY(EditAnywhere, Category="Condition", meta=(EditCondition="!bUseOverriddenValue"))
	FGameplayTagContainer DistanceDataTags;

	UPROPERTY(EditAnywhere, Category="Condition")
	bool bUseAddedOffset;

	UPROPERTY(EditAnywhere, Category="Condition", meta=(EditCondition="bUseAddedOffset"))
	float AddedOffset;

	UPROPERTY(EditAnywhere, Category="Condition")
	TEnumAsByte<EArithmeticKeyOperation::Type> Operator;

	UPROPERTY(EditAnywhere, Category="Condition")
	TEnumAsByte<ETargetDistanceComparisonType::Type> ComparisonType;

};

USTRUCT(BlueprintType)
struct FFortAIAssignmentIdentifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Assignment")
	EAssignmentType AssignmentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Assignment")
	FGameplayTagContainer AssignmentGameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Assignment")
	TEnumAsByte<EFortTeam::Type> AssignmentTeam;

};

USTRUCT()
struct FFortNavLinkPattern
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Pattern")
	int32 PatternBits;

	UPROPERTY(EditAnywhere, Category="Pattern")
	int32 WildcardBits;

};

