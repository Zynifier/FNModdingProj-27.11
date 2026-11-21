// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BuoyancyTypes.h"
#include "Engine/CollisionProfile.h"
#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "GameplayCueInterface.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Physics/FortPhysicsSimSize.h"
#include "FortPhysicsObjectPreset.generated.h"

class UFortPhysicsObjectBuoyancyData;
class UFortPhysicsObjectCollisionEffectsData;
class UFortPhysicsObjectImpactDamageData;
class UFortPhysicsObjectNavigationData;
class UFortPhysicsObjectPreset;
class UGameplayEffect;
class UNavArea;
class UPhysicalMaterial;

UENUM(BlueprintType)
enum class EFortPhysicsObjectType : uint8
{
	Invalid = 0,
	StaticObject = 1,
	PhysicsObject = 2,
	Vehicle = 3,
	Pawn = 4,
	Projectile = 5,
	Player = 6,
};

USTRUCT()
struct FImpulseDamageData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Impulse Damage Data")
	FScalableFloat MinValueForDamage;

	UPROPERTY(EditDefaultsOnly, Category="Impulse Damage Data")
	FScalableFloat PercentageOfDamage;

};

USTRUCT()
struct FImpulseResponseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Interaction Impulse Data")
	FGameplayTag GameplayTag;

	UPROPERTY(EditDefaultsOnly, Category="Interaction Impulse Data")
	FScalableFloat ImpulseMultiplier;

};

USTRUCT()
struct FInteractionImpulseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Interaction Impulse Data")
	FGameplayTag GameplayTag;

	UPROPERTY(EditDefaultsOnly, Category="Interaction Impulse Data")
	FScalableFloat ImpulseMagnitude;

	UPROPERTY(EditDefaultsOnly, Category="Interaction Impulse Data")
	uint8 bUseDamageToManageImpulse : 1;

	UPROPERTY(EditDefaultsOnly, Category="Interaction Impulse Data", meta=(EditCondition="bUseDamageToManageImpulse"))
	FScalableFloat DamageImpulseScale;

};

UCLASS(Config=Game, PerObjectConfig, BlueprintType)
class UFortPhysicsObjectAssetSetupData : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Setup Data|Defaults")
	TObjectPtr<UFortPhysicsObjectPreset> DefaultPhysicsPreset;

	UPROPERTY(EditAnywhere, Category="Setup Data|Defaults")
	TObjectPtr<UFortPhysicsObjectCollisionEffectsData> DefaultEffectsData;

	UPROPERTY(EditAnywhere, Category="Setup Data|Defaults")
	TObjectPtr<UPhysicalMaterial> DefaultPhysicalMaterial;

	UPROPERTY(EditAnywhere, Category="Setup Data|Defaults")
	TObjectPtr<UFortPhysicsObjectBuoyancyData> DefaultBuoyancyData;

	UPROPERTY(EditAnywhere, Category="Setup Data|Defaults")
	TObjectPtr<UFortPhysicsObjectImpactDamageData> DefaultImpactDamageData;

	UPROPERTY(EditAnywhere, Category="Setup Data|Defaults")
	TObjectPtr<UFortPhysicsObjectNavigationData> DefaultNavigationData;

	UPROPERTY(EditAnywhere, Category="Setup Data|Physics Preset (PhysicsObject.Preset tags)", meta=(Categories="PhysicsObject.Preset"))
	TMap<FGameplayTag, TObjectPtr<UFortPhysicsObjectPreset>> AssetSetupTagToPreset;

	UPROPERTY(EditAnywhere, Category="Setup Data|Physics Effects Data (PhysicsObject.PhysData tags)", meta=(Categories="PhysicsObject.PhysData"))
	TMap<FGameplayTag, TObjectPtr<UFortPhysicsObjectCollisionEffectsData>> AssetSetupTagToEffectData;

	UPROPERTY(EditAnywhere, Category="Setup Data|Physical Material Data (PhysicsObject.PhysData tags)", meta=(Categories="PhysicsObject.PhysData"))
	TMap<FGameplayTag, TObjectPtr<UPhysicalMaterial>> AssetSetupTagToPhysMat;

	UPROPERTY(EditAnywhere, Category="Setup Data|Navigation Data (PhysicsObject.PhysData tags)", meta=(Categories="PhysicsObject.PhysData"))
	TMap<FGameplayTag, TObjectPtr<UFortPhysicsObjectNavigationData>> AssetSetupTagToNavigationData;

	UPROPERTY(EditAnywhere, Category="Setup Data|Buoyancy Data (PhysicsObject.BuoyancyData tags)", meta=(Categories="PhysicsObject.BuoyancyData"))
	TMap<FGameplayTag, TObjectPtr<UFortPhysicsObjectBuoyancyData>> AssetSetupTagToBuoyancyData;

	UPROPERTY(EditAnywhere, Category="Setup Data|Impact Damage Data (PhysicsObject.ImpactDamageData tags)", meta=(Categories="PhysicsObject.ImpactDamageData"))
	TMap<FGameplayTag, TObjectPtr<UFortPhysicsObjectImpactDamageData>> AssetSetupTagToImpactDamageData;

	UPROPERTY(EditAnywhere, Config, EditFixedSize, Category="Physics Object Globals|Simulation Size Buckets", meta=(EditFixedOrder))
	TMap<EFortPhysicsSimSize, float> SimSizeBuckets;

};

UCLASS(Config=Game, PerObjectConfig)
class UFortPhysicsObjectBuoyancyData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="Buoyancy Data")
	float DefaultPontoonRadius;

	UPROPERTY(EditDefaultsOnly, Config, Category="Buoyancy Data")
	bool bSleepInsteadOfSink;

	UPROPERTY(EditDefaultsOnly, Config, Category="Buoyancy Data")
	float MinTimeInWaterToSink;

	UPROPERTY(EditDefaultsOnly, Category="Buoyancy Data")
	FBuoyancyData BuoyancyData;

};

UCLASS(Config=Game, PerObjectConfig, BlueprintType)
class UFortPhysicsObjectCollisionEffectsData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Impact Data")
	FGameplayCueTag ImpactEffectsCue;

	UPROPERTY(EditDefaultsOnly, Config, Category="Impact Data")
	float MinRetriggerTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="Impact Data")
	float MinRetriggerDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Impact Data|Water Thresholds")
	float MinWaterVelocityThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Impact Data|Water Thresholds")
	float MinMediumWaterVelocityThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Impact Data|Water Thresholds")
	float MinLargeWaterVelocityThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Impact Data|Water Thresholds")
	float MaxLargeWaterVelocityThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Impact Data|Impulse Thresholds")
	float MinImpulseMagnitude;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Impact Data|Impulse Thresholds")
	float MinMediumImpulseMagnitude;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Impact Data|Impulse Thresholds")
	float MinLargeImpulseMagnitude;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Impact Data|Impulse Thresholds")
	float MaxLargeImpulseMagnitude;

	UPROPERTY(EditDefaultsOnly, Category="Impact Data")
	FGameplayCueTag WaterEntryCue;

	UPROPERTY(EditDefaultsOnly, Category="Movement Data")
	FGameplayCueTag MovementEffectsCue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Movement Data")
	float LinearVelocityThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Movement Data")
	float AngularVelocityThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Movement Data")
	float RollingCosThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Movement Data")
	float MovingBufferTime;

};

UCLASS(Config=Game, PerObjectConfig)
class UFortPhysicsObjectImpactDamageData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="Impact Damage Data")
	bool bUseImpulseMagnitudeInsteadOfVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Impact Damage Data")
	TArray<FImpulseDamageData> PlayerImpactDamageBuckets;

	UPROPERTY(EditDefaultsOnly, Category="Impact Damage Data")
	TArray<FImpulseDamageData> EnvironmentImpactDamageBuckets;

	UPROPERTY(EditDefaultsOnly, Category="Impact Damage Data")
	FScalableFloat BaseOnImpactDamage;

	UPROPERTY(EditDefaultsOnly, Category="Impact Damage Data")
	FScalableFloat BaseEnvironmentalOnImpactDamage;

	UPROPERTY(EditDefaultsOnly, Category="Impact Damage Data")
	FScalableFloat BaseVehicleOnImpactDamage;

	UPROPERTY(EditDefaultsOnly, Category="Impact Damage Data")
	FScalableFloat BaseWildlifeOnImpactDamage;

	UPROPERTY(EditDefaultsOnly, Category="Impact Damage Data")
	FScalableFloat DelayBeforeNextImpactDamageEvent;

	UPROPERTY(EditDefaultsOnly, Category="Impact Damage Data", meta=(Categories="Fort.SurfaceType"))
	TMap<FGameplayTag, FScalableFloat> SourceSurfaceTypeToDamageModifier;

	UPROPERTY(EditDefaultsOnly, Category="Impact Damage Data", meta=(Categories="Fort.SurfaceType"))
	TMap<FGameplayTag, FScalableFloat> SourceSurfaceTypeToSpeedReductionPercentage;

};

UCLASS(Config=Game, PerObjectConfig)
class UFortPhysicsObjectNavigationData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Navigation Data")
	FScalableFloat LowSpeedSquareThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Navigation Data")
	FScalableFloat LowSpeedSquareDistanceThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Navigation Data")
	FScalableFloat LowSpeedRotationThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Navigation Data")
	FScalableFloat LowSpeedScaleThreshold;

	UPROPERTY(EditDefaultsOnly, Config, Category="Navigation Data")
	TSubclassOf<UNavArea> AreaClass;

	UPROPERTY(EditDefaultsOnly, Config, Category="Navigation Data")
	FVector FailsafeExtent;

	UPROPERTY(EditDefaultsOnly, Config, Category="Navigation Data")
	uint8 bIncludeAgentHeight : 1;

};

UCLASS(Config=Game, PerObjectConfig)
class UFortPhysicsObjectPreset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="General Data")
	FCollisionProfileName CollisionProfile;

	UPROPERTY(BlueprintReadOnly, Category="Interactions|Player Collision")
	float PlayerImpulseMagnitude;

	UPROPERTY(EditDefaultsOnly, Config, Category="Interactions|Player Collision")
	uint8 bIsAffectedByPlayerMovement : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Interactions|Player Collision")
	uint8 bCanAffectPlayerMovement : 1;

	UPROPERTY()
	uint8 bImpulseOnPlayerInteraction : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Interactions|Player Collision")
	uint8 bNotifyWhenBasedOn : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Interactions|Vehicle Collision")
	uint8 bCanInteractWithVehicles : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Interactions|Vehicle Collision")
	uint8 bTakeVehicleImpactDamage : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Interactions|Vehicle Collision", meta=(EditCondition="bTakeVehicleImpactDamage"))
	uint8 bOverrideVehicleImpactDamage : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Interactions|Vehicle Collision", meta=(EditCondition="bOverrideVehicleImpactDamage"))
	TSubclassOf<UGameplayEffect> PhysicsObjectVehicleImpactEffect;

	UPROPERTY(VisibleAnywhere, Category="Interactions|Water")
	TObjectPtr<UFortPhysicsObjectBuoyancyData> BuoyancyAsset;

	UPROPERTY(VisibleAnywhere, Config, Category="Interactions|Water")
	uint8 bCanInteractWithWater : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Defaults")
	uint8 bStartActive : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Defaults")
	uint8 bStartAwake : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Defaults")
	uint8 bEnableCCD : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Defaults")
	uint8 bWakeOnUnderneathObjectDestroyed : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Tick")
	uint8 bShouldEnableTick : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Impulse", meta=(DisplayPriority="2", EditCondition="bShouldImpulseOnDamage"))
	uint8 bWakeOnImpulse : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Damage", meta=(DisplayPriority="2"))
	uint8 bShouldImpulseOnDamage : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Damage", meta=(InlineEditConditionToggle))
	uint8 bLimitDownwardImpulseInWater : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Interaction", meta=(DisplayPriority="1"))
	uint8 bVelocityChangeOnDamageImpulse : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Interaction", meta=(DisplayPriority="1"))
	uint8 bOnlyAllowImpulseOnSpecificDamageTypes : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Interaction", meta=(DisplayPriority="2", EditCondition="bOnlyAllowImpulseOnSpecificDamageTypes"))
	TArray<FInteractionImpulseData> InteractionImpulseDataOverrides;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(InlineEditConditionToggle))
	uint8 bOverrideLinearDamping : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(InlineEditConditionToggle))
	uint8 bOverrideAngularDamping : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(InlineEditConditionToggle))
	uint8 bApplyLinearDrag2 : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(InlineEditConditionToggle))
	uint8 bApplyAngularDrag : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(InlineEditConditionToggle))
	uint8 bOverrideMassKg : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(InlineEditConditionToggle))
	uint8 bOverrideMassScale : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(InlineEditConditionToggle))
	uint8 bOverrideGravity : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(InlineEditConditionToggle))
	uint8 bOverrideErrorCorrectionValues : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(InlineEditConditionToggle))
	uint8 bOverridePhysicsReplicationMode : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides")
	uint8 bNeverKinematicAfterMovementStateUpdatesEnabled : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Impulse")
	float DefaultImpulseMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Impulse")
	float MaxImpulseMagnitude;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Impulse")
	TArray<FImpulseResponseData> ImpulseMultiplierOverrides;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Damage", meta=(ClampMin="0.000000", EditCondition="bLimitDownwardImpulseInWater"))
	float DownwardImpulseInWaterLimit;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bOverrideLinearDamping"))
	float LinearDampingOverride;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bOverrideAngularDamping"))
	float AngularDampingOverride;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bOverrideMassKg"))
	float MassKgOverride;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bOverrideMassKg"))
	bool bScaleMassWithObjectScale;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bOverrideMassScale"))
	float MassScaleOverride;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bOverrideGravity"))
	float GravityOverride;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bApplyLinearDrag2"))
	FVector LinearDrag2;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bApplyAngularDrag"))
	FVector AngularDrag;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bApplyAngularDrag"))
	FVector AngularDrag2;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bApplyAngularDrag"))
	FVector AngularDragWater;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bOverrideErrorCorrectionValues"))
	FRigidBodyErrorCorrection ErrorCorrectionOverride;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides", meta=(EditCondition="bOverridePhysicsReplicationMode"))
	EPhysicsReplicationMode PhysicsReplicationMode;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Overrides")
	float PawnCampDestroyTimer;

	UPROPERTY(VisibleDefaultsOnly, Category="Behavior|Overrides")
	TObjectPtr<UPhysicalMaterial> PhysicalMaterialOverride;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Tick", meta=(EditCondition="bShouldEnableTick"))
	float SleepLinearVelocity;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Tick", meta=(EditCondition="bShouldEnableTick"))
	float SleepAngularVelocity;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Tick", meta=(EditCondition="bShouldEnableTick"))
	float TimeToSleep;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Tick", meta=(EditCondition="bShouldEnableTick"))
	float TimeToDeactivate;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Damage", meta=(DisplayPriority="1"))
	float MinHitImpulseForNotify;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Damage", meta=(DisplayPriority="2", EditCondition="bShouldImpulseOnDamage"))
	float DamageImpulseMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Damage", meta=(DisplayPriority="2", EditCondition="bShouldImpulseOnDamage"))
	float MinDamageToImpulse;

	UPROPERTY(EditDefaultsOnly, Config, Category="Behavior|Damage", meta=(DisplayPriority="2", EditCondition="bShouldImpulseOnDamage"))
	float MinDamageToWakeAndImpulse;

	UPROPERTY(VisibleDefaultsOnly, Category="Behavior|Damage", meta=(DisplayPriority="0"))
	TObjectPtr<UFortPhysicsObjectImpactDamageData> ImpactDamageData;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Behavior|Collision Effects")
	TObjectPtr<UFortPhysicsObjectCollisionEffectsData> EffectsData;

private:
	UPROPERTY(VisibleAnywhere, Config, Category="Interactions|Water")
	float DefaultPontoonRadius;

	UPROPERTY(VisibleAnywhere, Config, Category="Interactions|Water")
	float MinTimeInWaterToSink;

	UPROPERTY(VisibleAnywhere, Config, Category="Interactions|Water")
	FBuoyancyData BuoyancyData;

};

UCLASS(EditInlineNew, BlueprintType, Blueprintable)
class UFortPluginPhysicsObjectAssetSetupData : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Setup Data|Physics Preset (PhysicsObject.Preset tags)", meta=(AssetBundles="Client,Server", Categories="PhysicsObject.Preset"))
	TMap<FGameplayTag, TSoftObjectPtr<UFortPhysicsObjectPreset>> AssetSetupTagToPreset;

	UPROPERTY(EditAnywhere, Category="Setup Data|Physics Effects Data (PhysicsObject.PhysData tags)", meta=(AssetBundles="Client,Server", Categories="PhysicsObject.PhysData"))
	TMap<FGameplayTag, TSoftObjectPtr<UFortPhysicsObjectCollisionEffectsData>> AssetSetupTagToEffectData;

	UPROPERTY(EditAnywhere, Category="Setup Data|Physical Material Data (PhysicsObject.PhysData tags)", meta=(AssetBundles="Client,Server", Categories="PhysicsObject.PhysData"))
	TMap<FGameplayTag, TSoftObjectPtr<UPhysicalMaterial>> AssetSetupTagToPhysMat;

	UPROPERTY(EditAnywhere, Category="Setup Data|Navigation Data (PhysicsObject.PhysData tags)", meta=(AssetBundles="Client,Server", Categories="PhysicsObject.PhysData"))
	TMap<FGameplayTag, TSoftObjectPtr<UFortPhysicsObjectNavigationData>> AssetSetupTagToNavigationData;

	UPROPERTY(EditAnywhere, Category="Setup Data|Buoyancy Data (PhysicsObject.BuoyancyData tags)", meta=(AssetBundles="Client,Server", Categories="PhysicsObject.BuoyancyData"))
	TMap<FGameplayTag, TSoftObjectPtr<UFortPhysicsObjectBuoyancyData>> AssetSetupTagToBuoyancyData;

	UPROPERTY(EditAnywhere, Category="Setup Data|Impact Damage Data (PhysicsObject.ImpactDamageData tags)", meta=(AssetBundles="Client,Server", Categories="PhysicsObject.ImpactDamageData"))
	TMap<FGameplayTag, TSoftObjectPtr<UFortPhysicsObjectImpactDamageData>> AssetSetupTagToImpactDamageData;

};

