// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "ScalableFloat.h"
#include "Abilities/GameplayEffectApplicationInfo.h"
#include "FortTeamEnum.h"
#include "FortAbilityTypes.generated.h"

class UFortAbilitySet;
class UObject;

UENUM(BlueprintType)
enum class EFortAbilityChargeState : uint8
{
	None = 0,
	ChargingUp = 1,
	MaxCharge = 2,
	Discharge = 3,
	ChargingDown = 4,
};

UENUM(BlueprintType)
enum class EFortDeliveryInfoBuildingActorSpecification : uint8
{
	All = 0,
	PlayerBuildable = 1,
	NonPlayerBuildable = 2,
};

UENUM(BlueprintType)
enum class EFortProximityBasedGEApplicationType : uint8
{
	/** Application pulses every ProximityPulseInterval seconds and will never be automatically removed */
	ApplyOnProximityPulse = 0,
	/** Application occurs only when the target touches the actor's touch component and will never be automatically removed */
	ApplyOnProximityTouch = 1,
	/** Application occurs only when the target touches the actor's touch component and will be automatically removed when the actor leaves the touch or the building becomes inactive */
	ApplyOnlyDuringProximityTouch = 2,
	/** Application occurs only when the target exits the actor's touch component and will never be automatically removed. */
	ApplyOnProximityExit = 3,
	/** Application pulses every ProximityPulseInterval - ProximityPrePulseTime seconds and will never be automatically removed. */
	ApplyOnProximityPrePulse = 4,
};

USTRUCT()
struct FAbilityTrackedActorSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Tracking")
	FScalableFloat MaximumTrackedActors;

};

USTRUCT(BlueprintType)
struct FActiveGameplayModifierHandle
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 Handle;

};

USTRUCT(BlueprintType)
struct FFortDeliveryInfoRequirementsFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	FGameplayTagRequirements SourceTagRequirements;

	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	FGameplayTagRequirements TargetTagRequirements;

	UPROPERTY(EditDefaultsOnly, Category="Requirements", meta=(EditCondition="bConsiderTeamAffiliationToInstigator"))
	TEnumAsByte<EFortTeamAffiliation::Type> ApplicableTeamAffiliation;

	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	uint8 bConsiderTeamAffiliationToInstigator : 1;

	UPROPERTY(EditDefaultsOnly, Category="Requirements", meta=(EditCondition="bConsiderTeam"))
	TEnumAsByte<EFortTeam::Type> ApplicableTeam;

	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	uint8 bConsiderTeam : 1;

	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	uint8 bApplyToPlayerPawns : 1;

	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	uint8 bApplyToAIPawns : 1;

	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	uint8 bApplyToBuildingActors : 1;

	UPROPERTY(EditDefaultsOnly, Category="Requirements", meta=(EditCondition="bApplyToBuildingActors"))
	EFortDeliveryInfoBuildingActorSpecification BuildingActorSpecification;

	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	uint8 bApplyToGlobalEnvironmentAbilityActor : 1;

};

USTRUCT(BlueprintType)
struct FFortAbilitySetDeliveryInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	FFortDeliveryInfoRequirementsFilter DeliveryRequirements;

	UPROPERTY(EditDefaultsOnly, Category="Abilities", meta=(AssetBundles="Equipped"))
	TArray<TSoftObjectPtr<UFortAbilitySet>> AbilitySets;

};

USTRUCT()
struct FFortConditionalIncludeTags
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Default")
	FGameplayTagContainer ConditionTags;

	UPROPERTY(EditAnywhere, Category="Default")
	FGameplayTagContainer IncludeTags;

};

USTRUCT()
struct FFortGameplayAbilityTargetDataContext : public FGameplayAbilityTargetData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint32 Context;

	UPROPERTY()
	uint32 Context2;

	UPROPERTY()
	uint8 bIsServerInstigated : 1;

};

USTRUCT()
struct FFortGameplayAbilityTargetData_SingleTargetHit : public FGameplayAbilityTargetData_SingleTargetHit
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 CartridgeID;

	UPROPERTY()
	float Timestamp;

	UPROPERTY()
	uint8 AntiCheatData[12];

};

USTRUCT()
struct FFortGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bIsFatalHit;

	UPROPERTY()
	bool bIsCriticalHit;

	UPROPERTY()
	bool bIsDiceCritical;

	UPROPERTY()
	bool bIsFullBodyHit;

	UPROPERTY()
	float KnockbackMagnitude;

	UPROPERTY()
	float KnockbackZAngle;

	UPROPERTY()
	float StunTime;

	UPROPERTY()
	float TotalChargeTime;

	UPROPERTY()
	float ChargeMagnitude;

	UPROPERTY()
	float EffectDirectionX;

	UPROPERTY()
	float EffectDirectionY;

	UPROPERTY()
	FGameplayTagContainer TooltipTags;

	UPROPERTY()
	int32 CartridgeID;

protected:
	UPROPERTY()
	FGuid ItemGuid;

	UPROPERTY()
	TWeakObjectPtr<UObject> DamageSourceObject;

	UPROPERTY()
	float SourceLevel;

	UPROPERTY()
	float UnmodifiedDamage;

	UPROPERTY()
	float ModifiedDamage;

};

USTRUCT()
struct FFortGameplayEffectDeliveryInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	FFortDeliveryInfoRequirementsFilter DeliveryRequirements;

	UPROPERTY(EditDefaultsOnly, Category="Effect")
	TArray<FGameplayEffectApplicationInfo> GameplayEffects;

};

USTRUCT()
struct FProximityBasedGEDeliveryInfoBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Requirements")
	FFortDeliveryInfoRequirementsFilter DeliveryRequirements;

	UPROPERTY(EditDefaultsOnly, Category="ApplicationType")
	EFortProximityBasedGEApplicationType ProximityApplicationType;

};

USTRUCT(BlueprintType)
struct FProximityBasedGEDeliveryInfo : public FProximityBasedGEDeliveryInfoBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Effects")
	TArray<FGameplayEffectApplicationInfo> EffectsToApply;

};

USTRUCT()
struct FProximityBasedGEDeliveryInfoHard : public FProximityBasedGEDeliveryInfoBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Effects")
	TArray<FGameplayEffectApplicationInfoHard> EffectsToApply;

};

