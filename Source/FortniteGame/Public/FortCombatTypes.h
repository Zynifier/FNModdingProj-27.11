// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortCombatTypes.generated.h"

class AActor;
class AController;
class AFortPawn;
class AFortPlayerState;
class UAnimSequenceBase;
class UFortAnimNotifyState_AbilityDecisionWindow;
class UFortWeaponItemDefinition;
class UObject;

UENUM(meta=(ScriptName="FortAIDirectorEventType"))
enum class EFortAIDirectorEvent : uint8
{
	/** Player events */// Currently STW only (only knows about STW enemy types)

	PlayerAIEnemies = 0,
	PlayerTakeDamage = 1,
	PlayerHealth = 2,
	PlayerDeath = 3,
	PlayerLookAtAIEnemy = 4,
	PlayerDamageAIEnemy = 5,
	PlayerKillAIEnemy = 6,
	PlayerHealingPotential = 7,
	// Currently STW only (but could be made generic)

	PlayerAmmoLight = 8,
	// Currently STW only (but could be made generic)

	PlayerAmmoMedium = 9,
	// Currently STW only (but could be made generic)

	PlayerAmmoHeavy = 10,
	// Currently STW only (but could be made generic)

	PlayerAmmoShells = 11,
	// Currently STW only (but could be made generic)

	PlayerAmmoEnergy = 12,
	// Currently STW only (only knows about STW enemy types)

	PlayerAINear = 13,
	PlayerMovement = 14,
	/** Encounter events */
	ObjectiveTakeDamage = 15,
	ObjectiveHealth = 16,
	ObjectiveDestroyed = 17,
	TrapFired = 18,
	TrapDamagedAIEnemy = 19,
	ObjectivePathCost = 20,
	PlayerPathCost = 21,
	ObjectiveNearbyBuildingDamaged = 22,
	Max_None = 23 UMETA(DisplayName="None"),
};

UENUM()
enum class EFortAIDirectorEventParticipant : uint8
{
	Target = 0,
	Source = 1,
	Either = 2,
	Max_None = 3,
};

UENUM()
enum class EFortAIDirectorFactor : uint8
{
	PlayerDamageThreat = 0,
	ObjectiveDamageThreat = 1,
	ObjectivePathCost = 2,
	PlayerPathCost = 3,
	PlayerMovement = 4,
	TrapsEffective = 5,
	PlayerWander = 6,
	NearbyEnemyPresence = 7,
	OffensiveResources = 8,
	DefensiveResources = 9,
	Boredom = 10,
	ArtilleryVulnerability = 11,
	Max_None = 12 UMETA(DisplayName="None"),
};

UENUM(BlueprintType)
namespace EFortAmmoType
{
	enum Type
	{
		Pistol = 0,
		//Light

		Shotgun = 1,
		//Shells

		Assault = 2,
		//Medium

		Sniper = 3,
		//Heavy

		Energy = 4,
	};
}

UENUM(BlueprintType)
namespace EFortBaseWeaponDamage
{
	enum Type
	{
		Combat = 0,
		// Base damage for striking a combat entity (usually a character or a pawn, but could be something like an explosive projectile, etc.)

		Environmental = 1,
	};
}

UENUM()
namespace EFortCombatEventContribution
{
	enum Type
	{
		Linear = 0,
		Inverse = 1,
		Accumulator = 2,
		Max_None = 3 UMETA(DisplayName="None"),
	};
}

UENUM()
namespace EFortCombatEvents
{
	enum Type
	{
		HuskFollowing = 0,
		SmasherFollowing = 1,
		TrollFollowing = 2,
		FlingerFollowing = 3,
		TakerFollowing = 4,
		HuskCombatNearby = 5,
		SmasherCombatNearby = 6,
		TrollCombatNearby = 7,
		FlingerCombatNearby = 8,
		TakerCombatNearby = 9,
		PlayerTakeDamage = 10,
		PlayerHealth = 11,
		PlayerLookAtEnemy = 12,
		PlayerDamageEnemy = 13,
		PlayerKilledEnemy = 14,
		AtlasTakeDamage = 15,
		AtlasHealth = 16,
		AtlasDestroyed = 17,
		TrapFiring = 18,
		BuildingTakeDamage = 19,
		FoodHealingPotential = 20,
		PlayerAmmo = 21,
		EnemiesNear = 22,
		PlayerMovement = 23,
		BuildingDamagedNearObjective = 24,
		TrapDamageEnemy = 25,
		ObjectivePathCost = 26,
		PlayerPathCost = 27,
		Max_None = 28 UMETA(DisplayName="None"),
	};
}

UENUM()
namespace EFortCombatFactors
{
	enum Type
	{
		PlayerDamageThreat = 0,
		ObjectiveDamageThreat = 1,
		ObjectivePathCost = 2,
		PlayerPathCost = 3,
		PlayerMovement = 4,
		TrapsEffective = 5,
		PlayerWander = 6,
		NearbyEnemyPresence = 7,
		OffensiveResources = 8,
		DefensiveResources = 9,
		Boredom = 10,
		ArtilleryVulnerability = 11,
		//Effective vs Individual AI

		Max_None = 12 UMETA(DisplayName="None"),
	};
}

UENUM(BlueprintType)
namespace EFortCombatThresholds
{
	enum Type
	{
		Low = 0,
		Medium = 1,
		High = 2,
		Extreme = 3,
		Max_None = 4 UMETA(DisplayName="None"),
	};
}

UENUM()
namespace EFortContributionGraphElements
{
	enum Type
	{
		ProportionalLine = 0,
		IntegralLine = 1,
		TotalLine = 2,
		PendingLine = 3,
		ActionLine = 4,
		Max_None = 5 UMETA(DisplayName="None"),
	};
}

UENUM(BlueprintType)
enum class EFortElementalDamageType : uint8
{
	None = 0,
	Fire = 1,
	Ice = 2,
	Lightning = 3,
	Energy = 4,
	MAX = 5 UMETA(hidden),
};

UENUM()
namespace EFortFactorContributionType
{
	enum Type
	{
		CurrentValue_Direct = 0,
		CurrentValue_Inverse = 1,
		AverageValue_Direct = 2,
		AverageValue_Inverse = 3,
	};
}

UENUM()
namespace EFortIntensityGraphElements
{
	enum Type
	{
		ActualIntensity = 0,
		DesiredIntensity = 1,
		Max_None = 2 UMETA(DisplayName="None"),
	};
}

UENUM()
enum class EFortMontageInputType : uint8
{
	// Responds at end of window, to either a click during window or hold at end

	WindowClickOrHold = 0,
	// Responds at end of window, to only a hold

	WindowHoldOnly = 1,
	// Responds immediately to a click, jumps to montage

	InstantClick = 2,
};

UENUM()
namespace EFortPIDValueGraphElements
{
	enum Type
	{
		Proportional = 0,
		Integral = 1,
		Max_None = 2 UMETA(DisplayName="None"),
	};
}

UENUM(BlueprintType)
namespace EFortReloadFXState
{
	enum Type
	{
		ReloadStart = 0,
		ReloadCartridge = 1,
		ReloadEnd = 2,
		Max_None = 3 UMETA(DisplayName="None"),
	};
}

UENUM(BlueprintType)
namespace EFortTargetingFXState
{
	enum Type
	{
		TargetingStart = 0,
		TargetingEnd = 1,
		Max_None = 2 UMETA(DisplayName="None"),
	};
}

UENUM(BlueprintType)
namespace EFortWeaponCoreAnimation
{
	enum Type
	{
		Melee = 0,
		Pistol = 1,
		Shotgun = 2,
		PaperBlueprint = 3,
		Rifle = 4,
		MeleeOneHand = 5,
		MachinePistol = 6,
		RocketLauncher = 7,
		GrenadeLauncher = 8,
		GoingCommando = 9,
		AssaultRifle = 10,
		TacticalShotgun = 11,
		SniperRifle = 12,
		TrapPlacement = 13,
		ShoulderLauncher = 14,
		AbilityDecoTool = 15,
		Crossbow = 16,
		C4 = 17,
		RemoteControl = 18,
		DualWield = 19,
		AR_BullPup = 20,
		AR_ForwardGrip = 21,
		MedPackPaddles = 22,
		SMG_P90 = 23,
		AR_DrumGun = 24,
		Consumable_Small = 25,
		Consumable_Large = 26,
		Balloon = 27,
		MountedTurret = 28,
		CreativeTool = 29,
		ExplosiveBow = 30,
		AshtonIndigo = 31,
		AshtonChicago = 32,
		MeleeDualWield = 33,
		Unarmed = 34,
		MAX = 35 UMETA(hidden),
	};
}

UENUM(BlueprintType)
namespace EFortWeaponSoundChannel
{
	enum Type
	{
		NormalA = 0,
		NormalB = 1,
		LowAmmo = 2,
		Degraded = 3,
		Max_None = 4 UMETA(DisplayName="None"),
	};
}

USTRUCT()
struct FFortAIDirectorEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortAIDirectorEvent Event;

	UPROPERTY()
	TObjectPtr<UObject> EventSource;

	UPROPERTY()
	TObjectPtr<UObject> EventTarget;

	UPROPERTY()
	float EventValue;

};

USTRUCT()
struct FFortActiveMontageDecisionWindow
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortAnimNotifyState_AbilityDecisionWindow> DecisionWindow;

	UPROPERTY()
	TObjectPtr<UAnimSequenceBase> DecisionAnimation;

	UPROPERTY()
	bool bReceivedPrimaryInput;

	UPROPERTY()
	bool bReceivedSecondaryInput;

	UPROPERTY()
	bool bAlreadyProcessedInput;

};

USTRUCT()
struct FFortCombatManagerEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float EventValue;

	UPROPERTY()
	TEnumAsByte<EFortCombatEvents::Type> Event;

};

USTRUCT()
struct FFortDamageSource
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AController> InstigatorController;

	UPROPERTY()
	TWeakObjectPtr<AActor> DamageCauser;

};

USTRUCT(BlueprintType)
struct FFortMontageInputAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction")
	FGameplayTag TriggerAbilityTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction")
	FName NextSection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InputAction")
	EFortMontageInputType InputType;

};

USTRUCT(BlueprintType)
struct FFortPlayerDeathReport
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	float ServerTimeForRespawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	float ServerTimeForResurrect;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	float LethalDamage;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	TObjectPtr<AFortPlayerState> KillerPlayerState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	TWeakObjectPtr<AFortPawn> KillerPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	float KillerHealthPercent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	float KillerShieldPercent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	float KillerOvershieldPercent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	TObjectPtr<UFortWeaponItemDefinition> KillerWeapon;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	TWeakObjectPtr<AActor> DamageCauser;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	uint8 bDroppedBackpack : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	uint8 bNotifyUI : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	FGameplayTagContainer Tags;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	FVector ViewLocationAtTimeOfDeath;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerDeathReport")
	FRotator ViewRotationAtTimeOfDeath;

};

USTRUCT()
struct FFortSurfaceDamageRatioByAffiliationStats : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Affiliation")
	float Friendly;

	UPROPERTY(EditDefaultsOnly, Category="Affiliation")
	float Neutral;

	UPROPERTY(EditDefaultsOnly, Category="Affiliation")
	float Hostile;

};

USTRUCT()
struct FFortSurfaceDamageRatioStats : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName Default;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName Wood;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName Stone;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName Metal;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName HumanEntity;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName AIEntity;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName Explosive;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName WeakSpot;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName Objective;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName WeakSpot_Wood;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName WeakSpot_Stone;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName WeakSpot_Metal;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	FName SupernaturalStructure;

	UPROPERTY(EditDefaultsOnly, Category="SurfaceRatio")
	TMap<FGameplayTag, FName> GenericSurfaceTag;

};

