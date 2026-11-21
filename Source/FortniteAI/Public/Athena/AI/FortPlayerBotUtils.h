// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlayerBotUtils.generated.h"

class ABuildingSMActor;

UENUM(BlueprintType)
enum class EAlertLevel : uint8
{
	/** Never saw a menace: idling & chilling (default perception) */
	Unaware = 0,
	/** Know there is a threat, but do not known its position */
	Suspicious = 1,
	/** Saw a menace already but lost LOS and have a last known position */
	LostTarget = 2,
	/** Highest level of alert, engaged in active fighting */
	Threatened = 3,
	Count = 4,
};

UENUM()
namespace EConstructionBuildingType
{
	enum Type
	{
		Wall = 0,
		Floor = 1,
		Stairs = 2,
		Roof = 3,
		Brace = 4,
		WallWindow = 5,
		Count = 6,
	};
}

UENUM()
enum class EDBNOPlayStyle : uint8
{
	/** Kills DBNO target no matter what is around */
	Thirsty = 0,
	/** Will only kill DBNO until safe to do, Passive = completely ignore DBNO */
	Default = 1,
	/** Completely ignore DBNO */
	Passive = 2,
	/** Thirsty but passive on human players */
	ThristyButPassiveOnPlayers = 3,
	/** Default but passive on human players */
	DefaultButPassiveOnPlayers = 4,
};

UENUM()
enum class ELeashReturnLocationMode : uint8
{
	/** Select the closest location on inner radius */
	Closest = 0,
	/** Select a random location inside the leash */
	Random = 1,
	/** Return to leash center */
	ReturnToCenter = 2,
	/** Try returning to leash center and avoid obstacles */
	ReturnToCenterAvoidObstacle = 3,
};

UENUM()
namespace ELookAtType
{
	enum Type
	{
		/** Unaware nervously looking around */
		ScanAround = 0,
		/** LKP look at investigation */
		Investigate = 1,
		/** LKP heard sound look at */
		HeardSound = 2,
		/** LKP look at Ambush */
		Ambush = 3,
		MAX = 4,
	};
}

UENUM()
namespace EOrientedConstructionBuildingType
{
	enum Type
	{
		WallX = 0,
		WallY = 1,
		Floor = 2,
		StairsUpX = 3,
		StairsUpY = 4,
		StairsDownX = 5,
		StairsDownY = 6,
		Roof = 7,
		BraceLeftX = 8,
		BraceRightX = 9,
		BraceLeftY = 10,
		BraceRightY = 11,
		WallWindowX = 12,
		WallWindowY = 13,
		Count = 14,
	};
}

UENUM()
namespace EPerceptionSoundType
{
	enum Type
	{
		/** Curve used when no other curve is used */
		Default = 0,
		/** Explosion */
		Explosion = 1,
		/** Fly by projectile */
		ProjectileFlyBy = 2,
		/** Projectile impact */
		ProjectileImpact = 3,
		/** Weapon Firing */
		WeaponFiring = 4,
		/** Building */
		Building = 5,
		/** MeleeImpact */
		MeleeImpact = 6,
		MAX = 7,
	};
}

UENUM()
enum class EPerceptionState : uint8
{
	/** Seeing the threat */
	Threat_Seeing = 0,
	/** know there is a threat but lost LOS (Last Know Position) */
	Threat_LKP = 1,
	/** Know there is a threat in a direction, but do not know its position */
	Threat_Alerted = 2,
	/** Recognized that there is an smashable obstacle on our path or we bumped into one*/
	ObstacleIncoming = 3,
	/** Recognized that there is an smashable obstacle blocked by into one*/
	ObstacleBlockedBy = 4,
	/** Recognized that there is an trap blocking us */
	ObstacleDetectedTrap = 5,
	/** Unknown state */
	Unknown = 6,
	Count = 6,
	Threat_Count = 3,
};

UENUM()
enum class EStimType : uint8
{
	/** Having a LOS on the actor from sight perception */
	Seeing = 0,
	/** Lost LOS on the actor from sight perception */
	Seen = 1,
	/** Did not have time to recognized target, but enough to do something */
	MightHaveSeen = 2,
	/** Received damage from this actor from damage perception */
	Hurt = 3,
	/** Heard noise from this actor from hearing perception */
	Heard = 4,
	/** Obstacle that is blocking us or ahead of us*/
	Obstacle = 5,
	/** Teammate marked an enemy */
	Enemy = 6,
	/** Enemy was touched */
	Touched = 7,
	// Add new one here

	Unknown = 8,
	Count = 8,
};

UENUM()
namespace ETrackingOffsetModifierCurve
{
	enum Type
	{
		/** Curve used when no other curve is used */
		Default = 0,
		/** Curve used when combat against threat just started */
		CombatStart = 1,
		/** Curve used when target is under a specific health threshold */
		TargetLowHealth = 2,
		/** Invalid */
		MAX = 3,
	};
}

USTRUCT(BlueprintType)
struct FConstructionBuildingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ConstructionBuildingInfo", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	TSubclassOf<ABuildingSMActor> BuildingActorClass[3];

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FLeashInfoOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Leash")
	float LeashInnerRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Leash")
	float LeashOuterRadius;

};

