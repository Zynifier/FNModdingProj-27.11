// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScalableFloat.h"
#include "FortExperienceSettingsComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortExperienceSettingsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Voice Chat")
	FScalableFloat VoiceChat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Vitals")
	FScalableFloat Invincibility;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Vitals")
	FScalableFloat StartingHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Vitals")
	FScalableFloat MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Vitals")
	FScalableFloat StartingShield;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Vitals")
	FScalableFloat MaxShields;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Vitals")
	FScalableFloat DBNOType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Controls")
	FScalableFloat AimAssistAllowed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Spawning")
	FScalableFloat RespawnHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Spawning")
	FScalableFloat RespawnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Spawning")
	FScalableFloat SpawnLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Spawning")
	FScalableFloat OverrideSpawnImmunityTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Spawning")
	FScalableFloat SpawnImmunityTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Building")
	FScalableFloat BuildingMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat DropAllItemsOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat DropAllResourcesOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat DropAllGameResourcesOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat InstantReload;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat InfiniteAmmo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat InfiniteConsumables;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat InfiniteResources;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat AllowItemDrop;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat AllowItemPickUp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat MaxItemSlots;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat WoodResourceWidgetVisible;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat StoneResourceWidgetVisible;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat MetalResourceWidgetVisible;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Inventory")
	FScalableFloat GoldCurrencyResourceWidgetVisible;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Siphon")
	FScalableFloat HealthSiphonValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Siphon")
	FScalableFloat WoodSiphonValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Siphon")
	FScalableFloat StoneSiphonValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Siphon")
	FScalableFloat MetalSiphonValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Siphon")
	FScalableFloat GoldSiphonValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Self Damage")
	FScalableFloat DamageToDeal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Self Damage")
	FScalableFloat RequiresNonZeroDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Self Damage")
	FScalableFloat TargetQueryIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Self Damage")
	FScalableFloat WeaponQueryIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Movement")
	FScalableFloat FallDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Movement")
	FScalableFloat MovementMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Movement")
	FScalableFloat Gravity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Movement")
	FScalableFloat ApplyJumpPenalty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Movement")
	FScalableFloat GliderRedeploy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Movement")
	FScalableFloat FlyEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Movement")
	FScalableFloat AllowFlightSprint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Movement")
	FScalableFloat FlySpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Game Rules")
	FScalableFloat PlayerLives;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Game Rules")
	FScalableFloat EliminationsToScoreMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Game Rules")
	FScalableFloat AssistsToScoreMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Game Rules")
	FScalableFloat AllowFriendlyFire;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Game Rules")
	FScalableFloat VehiclesDamageObjects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Game Rules")
	FScalableFloat VehiclesDamageVehicles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Resources")
	FScalableFloat HarvestRateMutliplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Resources")
	FScalableFloat HarvestStyle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|Resources")
	FScalableFloat MaximumResources;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|UI")
	FScalableFloat NameplateDisplayMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|UI")
	FScalableFloat LimitNamePlateMaxDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|UI")
	FScalableFloat NameplateDisplayDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|UI")
	FScalableFloat NameplateFocusAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|UI")
	FScalableFloat NameplateFocusTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|UI")
	FScalableFloat NameplateFocusMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|UI")
	FScalableFloat NameplateLineOfSight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|UI")
	FScalableFloat PlayerHealthIndicatorDisplayMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Experience Settings|UI")
	FScalableFloat CreativeBossHealthDisplayMode;

};

