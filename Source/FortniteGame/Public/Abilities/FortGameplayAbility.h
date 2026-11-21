// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "ActiveGameplayEffectHandle.h"
#include "Engine/DataTable.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "AI/FortAITypes.h"
#include "Abilities/FortAbilityTargetSelection.h"
#include "Abilities/FortAbilityTypes.h"
#include "Abilities/FortCharacterPartMontageInfo.h"
#include "Abilities/FortGameplayEffectContainerSpec.h"
#include "FortAnalyticsInterface.h"
#include "FortDamageSourceInterface.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortHolsterWeaponSourceInterface.h"
#include "UI/FortTooltipInterface.h"
#include "FortGameplayAbility.generated.h"

class AActor;
class AFortPawn;
class AFortPlayerPawn;
class AFortProjectileBase;
class AFortWeapon;
class APlayerController;
class UAnimMontage;
class UFortAbilitySystemComponent;
class UFortCameraMode;
class UFortGameplayAbilityMod;
class UFortItemDefinition;
class UFortTooltip;
class UFortTooltipDisplayStatsList;
class UFortWeaponItemDefinition;
class UFortWorldItemDefinition;
class UGameplayAbility;
class UGameplayEffect;
class UObject;
class UTexture2D;
enum class EFortAbilityChargeState : uint8;
enum class EFortGetPlayerPawnExecutions : uint8;

UENUM(BlueprintType)
enum class EFortAIWeaponUsage : uint8
{
	NoWeaponUsage = 0,
	UsesRangedWeapon = 1,
	UsesMeleeWeapon = 2,
};

UENUM()
enum class EFortAbilityCostSource : uint8
{
	// Uses the player's stamina

	Stamina = 0,
	// Uses the durability of the item owning this ability

	Durability = 1,
	// Use ammo out of a weapon's magazine, only supported for weapons

	AmmoMagazine = 2,
	// Use the item's primary ammo type, supported for weapons and gadgets

	AmmoPrimary = 3,
	// Use an arbitrary item definition as a cost

	Item = 4,
};

UENUM(BlueprintType)
enum class EFortGameplayAbilityActivation : uint8
{
	// Abilities that always apply gameplay effects and/or tags

	Passive = 0,
	// Abilities that are activated by a trigger

	Triggered = 1,
	// Abilities that are activated by player actions

	Active = 2,
};

UENUM(BlueprintType)
enum class EFortGameplayAbilityMontageSectionToPlay : uint8
{
	FirstSection = 0,
	RandomSection = 1,
	TestedRandomSection = 2 UMETA(Tooltip="Chooses a random section but tests only the minimum sections required to check different distances for ability to hit."),
};

UENUM()
enum class EFortGameplayAbilityTagChangedActionType : uint8
{
	Cancel = 0,
};

UENUM()
enum class EFortGameplayAbilityTagChangedEvent : uint8
{
	/** This event will only happen if this tag does not previously exist on the owner and has just been added. */
	NewlyAdded = 0,
	/** This event will happen any time the tag count has increased on the owner, even if it has just been newly added. */
	Increased = 1,
	/** This event will only happen if this tag previously existed on the owner, and it was just fully removed. */
	FullyRemoved = 2,
	/** This event will happen any time the tag count has decreased on the owner, even if the tag still exists after it was decreased. */
	Decreased = 3,
};

UENUM(BlueprintType)
enum class EFortGetPlayerPawnExecutions : uint8
{
	ValidFortPlayerPawn = 0,
	AvatarCastFailed = 1,
};

USTRUCT(BlueprintType)
struct FFortAbilityCost
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AbilityCost")
	EFortAbilityCostSource CostSource;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AbilityCost")
	FScalableFloat CostValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AbilityCost")
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AbilityCost")
	bool bOnlyApplyCostOnHit;

};

USTRUCT()
struct FFortGameplayAbilityBehaviorDistanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Behavior")
	FGameplayTagContainer DistanceDataTag;

	UPROPERTY(EditAnywhere, Category="Behavior")
	float Distance;

};

USTRUCT(BlueprintType)
struct FFortGameplayAbilityMontageInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	TObjectPtr<UAnimMontage> MontageToPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	float AnimPlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	float AnimRootMotionTranslationScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	EFortGameplayAbilityMontageSectionToPlay MontageSectionToPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	FName OverrideSection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	bool bPlayRandomSection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	TArray<FFortCharacterPartMontageInfo> CharacterPartMontages;

};

USTRUCT(BlueprintType)
struct FFortGameplayAbilityTagChangedAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbilityTagChangedAction")
	EFortGameplayAbilityTagChangedEvent Trigger;

	UPROPERTY()
	EFortGameplayAbilityTagChangedActionType Action;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbilityTagChangedAction")
	FGameplayTag Tag;

};

USTRUCT(BlueprintType)
struct FFortGameplayEffectContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectContainer")
	FGameplayTag ApplicationTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectContainer")
	FFortAbilityTargetSelectionList TargetSelection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectContainer")
	TArray<TSubclassOf<UGameplayEffect>> TargetGameplayEffectClasses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectContainer")
	TArray<TSubclassOf<UGameplayEffect>> OwnerGameplayEffectClasses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectContainer", meta=(Categories="GameplayCue"))
	FGameplayTagContainer ActivationCues;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectContainer", meta=(Categories="GameplayCue"))
	FGameplayTagContainer ImpactCues;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectContainer", meta=(Categories="GameplayCue"))
	bool bUseCalculationInTooltips;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectContainer")
	bool bOverrideChargeMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectContainer", meta=(ClampMax="1.000000", ClampMin="0.000000", EditCondition="bOverrideChargeMagnitude"))
	float ChargeMagnitudeOverrideValue;

};

USTRUCT(BlueprintType)
struct FProjectileTrajectorySplineInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	TObjectPtr<AActor> Instigator;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	FVector InitialLocation;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	FVector InitialVelocity;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	float MaxSpeed;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	float Gravity;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	float Friction;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	float Bounciness;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	float TimeStep;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	float TraceExtent;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	TEnumAsByte<ECollisionChannel> TraceChannel;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	FName CollisionProfile;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo", meta=(ClampMin="0.000000"))
	int32 MaxBounces;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	int32 MaxSteps;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	float MaxDistanceBetweenSplinePoints;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo", meta=(ClampMin="0.000000"))
	float InitialDistance;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	TArray<TObjectPtr<AActor>> ExtraActorsToIgnore;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	float LinearDamping;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileTrajectorySplineInfo")
	bool bReturnPhysicalMaterial;

};

UCLASS(MinimalAPI)
class UFortGameplayAbility : public UGameplayAbility, public IFortDamageSourceInterface, public IFortTooltipInterface, public IFortAnalyticsInterface, public IFortDataRegistryResolverScopeInterface, public IFortHolsterWeaponSourceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability")
	FORTNITEGAME_API virtual void AddDynamicGameplayEffectContainer(UPARAM(ref) FGameplayTag& ApplicationTag, UPARAM(ref) FFortGameplayEffectContainer& Container);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static FORTNITEGAME_API void AllowAIMovement(UGameplayAbility* OwningAbility);

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API FVector ApplyAccuracyToTargetLocation(const FVector& SourceLocation, const FVector& TargetLocation, float inDesiredThrowAngle) const;

	UFUNCTION(BlueprintCallable, Category="Ability")
	FORTNITEGAME_API virtual const TArray<FActiveGameplayEffectHandle> ApplyGameplayEffectContainer(FGameplayAbilityTargetDataHandle TargetData, FGameplayTag ApplicationTag, int32 GameplayEffectLevel = 1);

	UFUNCTION(BlueprintCallable, Category="Ability")
	FORTNITEGAME_API const TArray<FActiveGameplayEffectHandle> ApplyGameplayEffectContainerWithCSVStats(FGameplayAbilityTargetDataHandle TargetData, FGameplayTag ApplicationTag, int32 GameplayEffectLevel, const FString& StatName);

	UFUNCTION(BlueprintCallable, Category="Ability")
	FORTNITEGAME_API bool ApplySourcePropertyOverrides(TArray<FName>& OverriddenPropertyNames);

	UFUNCTION(BlueprintPure, Category="Ability|Cooldowns", meta=(DisplayName="GetCooldownTags"))
	FORTNITEGAME_API FGameplayTagContainer BP_GetCooldownTags() const;

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(DisplayName="GetGameplayEffectContainer"))
	FORTNITEGAME_API virtual FFortGameplayEffectContainer BP_GetGameplayEffectContainer(FGameplayTag ApplicationTag);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(DisplayName="GetGameplayEffectContainers"))
	FORTNITEGAME_API virtual void BP_GetGameplayEffectContainers(FGameplayTag ApplicationTag, TArray<FFortGameplayEffectContainer>& OutContainers);

	UFUNCTION(BlueprintCallable, Category="Projectile", meta=(AutoCreateRefTerm="ExtraActorsToIgnore", TraceChannel="ECC_GameTraceChannel8"))
	static FORTNITEGAME_API void CalculateProjectileTrajectorySpline(TArray<FVector>& OutSplinePoints, TArray<FVector>& OutSplineTangents, float& OutSimulatedTotalTime, const AActor* Instigator, FVector InitialLocation, FVector InitialVelocity, float MaxSpeed, float Gravity, float Friction, float Bounciness, float TimeStep, float TraceExtent, ECollisionChannel TraceChannel, const TArray<AActor*>& ExtraActorsToIgnore, int32 MaxBounces = 3, int32 MaxSteps = 70, float MaxDistanceBetweenSplinePoints = 1500.000000f, float InitialDistance = 0.000000f, const float LinearDamping = 0.000000f, bool bReturnPhysicalMaterial = false);

	UFUNCTION(BlueprintCallable, Category="Projectile", meta=(AutoCreateRefTerm="ExtraActorsToIgnore", TraceChannel="ECC_GameTraceChannel8"))
	static FORTNITEGAME_API void CalculateProjectileTrajectorySplineProfile(TArray<FVector>& OutSplinePoints, TArray<FVector>& OutSplineTangents, float& OutSimulatedTotalTime, const AActor* Instigator, FVector InitialLocation, FVector InitialVelocity, float MaxSpeed, float Gravity, float Friction, float Bounciness, float TimeStep, float TraceExtent, FName CollisionProfile, const TArray<AActor*>& ExtraActorsToIgnore, int32 MaxBounces = 3, int32 MaxSteps = 70, float MaxDistanceBetweenSplinePoints = 1500.000000f, float InitialDistance = 0.000000f, const float LinearDamping = 0.000000f, bool bReturnPhysicalMaterial = false);

	UFUNCTION(BlueprintCallable, Category="Projectile", meta=(AutoCreateRefTerm="ExtraActorsToIgnore", TraceChannel="ECC_GameTraceChannel8"))
	static FORTNITEGAME_API void CalculateProjectileTrajectorySplineWithHit(FHitResult& OutHitResult, TArray<FVector>& OutSplinePoints, TArray<FVector>& OutSplineTangents, float& OutSimulatedTotalTime, const AActor* Instigator, FVector InitialLocation, FVector InitialVelocity, float MaxSpeed, float Gravity, float Friction, float Bounciness, float TimeStep, float TraceExtent, ECollisionChannel TraceChannel, const TArray<AActor*>& ExtraActorsToIgnore, int32 MaxBounces = 3, int32 MaxSteps = 70, float MaxDistanceBetweenSplinePoints = 1500.000000f, float InitialDistance = 0.000000f, const float LinearDamping = 0.000000f, bool bReturnPhysicalMaterial = false);

	UFUNCTION(BlueprintCallable, Category="Projectile", meta=(AutoCreateRefTerm="ExtraActorsToIgnore", TraceChannel="ECC_GameTraceChannel8"))
	static FORTNITEGAME_API void CalculateProjectileTrajectorySplineWithHitProfile(FHitResult& OutHitResult, TArray<FVector>& OutSplinePoints, TArray<FVector>& OutSplineTangents, float& OutSimulatedTotalTime, const AActor* Instigator, FVector InitialLocation, FVector InitialVelocity, float MaxSpeed, float Gravity, float Friction, float Bounciness, float TimeStep, float TraceExtent, FName CollisionProfile, const TArray<AActor*>& ExtraActorsToIgnore, int32 MaxBounces = 3, int32 MaxSteps = 70, float MaxDistanceBetweenSplinePoints = 1500.000000f, float InitialDistance = 0.000000f, const float LinearDamping = 0.000000f, bool bReturnPhysicalMaterial = false);

	UFUNCTION(BlueprintCallable, Category="Ability")
	FORTNITEGAME_API void ClearAIFocalPoint(bool bUseAttackingPriority);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="ActorTracking")
	FORTNITEGAME_API void ClearTrackedActors(bool bDestroyActors = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="ActorTracking")
	FORTNITEGAME_API void ClearTrackedGroupedActors(FGameplayTag GroupTag, bool bDestroyActors = true);

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API bool DoesTargetHaveProhibitedTagsForAI(const AActor* Target) const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API bool DoesTargetHaveTags(const AActor* Target, const FGameplayTagContainer& Tags) const;

	UFUNCTION(BlueprintCallable, Category="AbilityWeapon")
	FORTNITEGAME_API void EquipAbilityWeapon(UFortWeaponItemDefinition* WeaponDefinition, int32 ItemLevel = 0);

	UFUNCTION(BlueprintCallable, Category="VehicleWeapon")
	FORTNITEGAME_API void EquipVehicleWeapon(UFortWeaponItemDefinition* WeaponDefinition, const int32 SeatIndex = 0, const int32 ItemLevel = 0);

	UFUNCTION(BlueprintImplementableEvent, Category="Ability")
	FORTNITEGAME_API void FailedToActivatePassiveAbility(FGameplayAbilityActorInfo ActorInfo);

	UFUNCTION(BlueprintCallable, Category="Camera")
	FORTNITEGAME_API void ForceCameraLookDown(APlayerController* PC);

	UFUNCTION(BlueprintPure, Category="Tags")
	FORTNITEGAME_API FGameplayTagContainer GetAbilityTags() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Ability")
	FORTNITEGAME_API float GetAbilityTargetingLevel() const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API UFortAbilitySystemComponent* GetActivatingAbilityComponent() const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API AFortPawn* GetActivatingPawn() const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API AActor* GetAIAbilityTarget() const;

	UFUNCTION(BlueprintCallable, Category="Utility")
	FORTNITEGAME_API FVector GetAimLocationNearestPawn(AFortPawn* Instigator);

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API AFortPlayerPawn* GetAvatarAsFortPlayerPawn() const;

	UFUNCTION(BlueprintCallable, meta=(ExpandEnumAsExecs="OutExec"))
	FORTNITEGAME_API void GetAvatarAsValidFortPlayerPawn(EFortGetPlayerPawnExecutions& OutExec, AFortPlayerPawn*& OutFortPlayerPawn);

	UFUNCTION(BlueprintPure, Category="ChargeUp")
	FORTNITEGAME_API float GetChargePercent() const;

	UFUNCTION(BlueprintPure, Category="ChargeUp")
	FORTNITEGAME_API EFortAbilityChargeState GetChargeState() const;

	UFUNCTION(BlueprintPure, Category="ChargeUp")
	FORTNITEGAME_API float GetChargeTime() const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API void GetCurrentAbilitySourceLevel(float& OutSourceLevel) const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API UFortWorldItemDefinition* GetCurrentSourceItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API AFortWeapon* GetCurrentSourceWeapon() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Ability")
	FORTNITEGAME_API FTransform GetCustomAbilitySourceTransform() const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API FVector GetFireLocation() const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API FRotator GetFireRotation(bool bApplyLeading = true, bool bApplyInaccuracy = false, bool bApplyClampedMaxYawAngleToFire = false) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="ActorTracking")
	FORTNITEGAME_API int32 GetMaxNumTrackedActors() const;

	UFUNCTION(BlueprintPure, Category="HeroLoadout")
	FORTNITEGAME_API int32 GetOwningPlayerTeamPerkProgressiveActivationLevel() const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API void GetProjectileInitialValues(float& outProjectileSpeed, FRotator& outSpawnDirection, float& outProjectileGravity, AActor*& HomingTarget, bool bApplyInaccuracy = true, bool bApplyClampedMaxYawAngleToFire = true, bool bApplyLeading = true, float DesiredFlightTime = 0.000000f) const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API void GetProjectileInitialValuesAndTargetLocation(AActor* AbilityTarget, FVector& outTargetLocation, float& outProjectileSpeed, FRotator& outSpawnDirection, float& outProjectileGravity, AActor*& HomingTarget, bool bApplyInaccuracy = true, bool bApplyClampedMaxYawAngleToFire = true, bool bApplyLeading = true, float DesiredFlightTime = 0.000000f) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly, Category="ActorTracking")
	FORTNITEGAME_API TArray<AActor*> GetTrackedActors() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly, Category="ActorTracking")
	FORTNITEGAME_API TArray<AActor*> GetTrackedGroupedActors(FGameplayTag GroupTag) const;

	UFUNCTION(BlueprintPure, Category="ChargeUp")
	FORTNITEGAME_API bool IsChargeUpAbility() const;

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API bool IsTargetOutsideOfMaxYawRotation() const;

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(DisplayName="AbilityCompleted"))
	FORTNITEGAME_API virtual void K2_AbilityCompleted();

	UFUNCTION(BlueprintNativeEvent, Category="Ability", meta=(DisplayName="OverrideFailedReason", ScriptName="OverrideFailedReason"))
	FORTNITEGAME_API void K2_OverrideFailedReason(const FGameplayTagContainer& FailedReason, FGameplayTagContainer& OverridenFailedReason);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Ability", meta=(DisplayName="ShouldUseDecoTool"))
	FORTNITEGAME_API bool K2_ShouldUseDecoTool(FGameplayAbilityActorInfo ActorInfo) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Ability", meta=(DisplayName="TriggerFromAnimation"))
	FORTNITEGAME_API void K2_TriggerFromAnimation(FGameplayTag ApplicationTag);

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API virtual FFortGameplayEffectContainerSpec MakeGameplayEffectContainerSpec(FGameplayTag ApplicationTag, int32 GameplayEffectLevel = 1) const;

	UFUNCTION(BlueprintCallable, Category="Ability")
	FORTNITEGAME_API virtual void MakeGameplayEffectContainerSpecs(FGameplayTag ApplicationTag, int32 GameplayEffectLevel, TArray<FFortGameplayEffectContainerSpec>& OutSpecContainers);

	UFUNCTION(BlueprintImplementableEvent, Category="Ability")
	FORTNITEGAME_API void OnActiveAbilityInputRetriggered();

	UFUNCTION(BlueprintNativeEvent, Category="Ability")
	FORTNITEGAME_API void OnGenericNotifyFromAnimation(FGameplayTag NotifyTag);

	UFUNCTION(BlueprintImplementableEvent, Category="Ability")
	FORTNITEGAME_API void OnOwnerJumpPressed();

	UFUNCTION(BlueprintCallable, Category="Camera")
	FORTNITEGAME_API void PopCameraMode();

	UFUNCTION(BlueprintCallable, Category="Camera")
	FORTNITEGAME_API void PushCameraMode(TSubclassOf<UFortCameraMode> CameraModeClass);

	UFUNCTION(BlueprintPure, Category="Ability")
	FORTNITEGAME_API void QueryGameplayEffectContainerTargetExecutionModifiers(FGameplayAbilityTargetDataHandle TargetData, const UFortAbilitySystemComponent* SrcAbilitySystem, FGameplayTag ApplicationTag, int32 GameplayEffectLevel, const UObject* SourceObject, const TArray<FGameplayEffectExecutionScopedModifierInfo>& InScopedMods, TArray<FActiveGameplayEffectHandle> InIgnoreHandles, TArray<FGameplayModifierEvaluatedData>& OutOutputModifiers, bool bTooltipRequest = false) const;

	UFUNCTION(BlueprintCallable, Category="Ability")
	FORTNITEGAME_API void SetAIFocalPoint(AActor* FocusTarget, FVector FocalPoint, bool bUseAttackingPriority);

	UFUNCTION(BlueprintNativeEvent, Category="Ability")
	FORTNITEGAME_API bool SetupPreviewImageOverride();

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API bool ShouldPlayFailedMontage(const FGameplayTagContainer& FailedReason) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="ActorTracking")
	FORTNITEGAME_API void TrackActor(AActor* ActorToTrack);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="ActorTracking")
	FORTNITEGAME_API void TrackGroupedActor(AActor* ActorToTrack, FGameplayTag GroupTag);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activation")
	EFortGameplayAbilityActivation ActivationType;

	UPROPERTY(EditDefaultsOnly, Category="GameplayEffects", meta=(DisplayName="Gameplay Effect Containers"))
	FFortGameplayEffectContainer EffectContainers[5];

	UPROPERTY()
	TArray<FFortGameplayEffectContainer> GameplayEffectContainers;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FFortGameplayEffectContainer> DynamicGameplayEffectContainers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
	FGameplayTagContainer OwnerPreviewImageOverrideTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
	TSubclassOf<AFortProjectileBase> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category="Advanced", meta=(DisplayAfter="ReplicationPolicy"))
	bool bAllowBlueprintReplicatedVariables;

	UPROPERTY(EditAnywhere, Category="Damage")
	FDataTableRowHandle DamageStatHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Costs")
	TArray<FFortAbilityCost> AbilityCosts;

	UPROPERTY(EditDefaultsOnly, Category="Costs")
	uint8 bShowWidgetForCosts : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Costs")
	uint8 bApplyingCostsEnabled : 1;

	UPROPERTY(EditDefaultsOnly, Category="Cooldowns|Explicit")
	FScalableFloat ExplicitCooldownDuration;

	UPROPERTY(EditDefaultsOnly, Category="Cooldowns|Explicit")
	FGameplayTagContainer ExplicitCooldownTags;

	UPROPERTY(EditDefaultsOnly, Category="Cooldowns|Explicit")
	FGameplayTagContainer ExplicitCooldownAssetTags;

	UPROPERTY(EditDefaultsOnly, Category="Cooldowns")
	uint8 bStartWithCooldown : 1;

	UPROPERTY(EditDefaultsOnly, Category="Cooldowns")
	uint8 bPersistOnDeath : 1;

	UPROPERTY(EditDefaultsOnly, Category="Advanced")
	uint8 bDisableMoveCombining : 1;

	UPROPERTY(EditDefaultsOnly, Category="Advanced")
	uint8 bIgnoreClientActivationAttempts : 1;

	UPROPERTY(EditDefaultsOnly, Category="Channeling")
	FScalableFloat MovementCancellationLeashLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	uint8 bStopsAIBehaviorLogic : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	uint8 bStopsAIMovement : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	uint8 bStopsRVOAvoidance : 1;

	UPROPERTY()
	uint8 bForceNormalAILOD_DEPRECATED : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	EFortAILODLevel MinimumRequiredAILODLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	uint8 bRelevantForAIDespawning : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	uint8 bUseTetheredPawnAsInstigator : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	uint8 bUseAIFireLocationAndRotation : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	EFortAIWeaponUsage AIWeaponUsage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	FGameplayTag WeaponTestApplicationTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	uint8 bVerifyFireOffsetIsNotObstructedByWorldGeometry : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	uint8 bCanHitBallisticTestsOnlyTestIndesructiblesWhileFalling : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	FVector FireOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="0", UIMin="0"))
	float ActivationNoiseRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="0", UIMin="0"))
	float ImpactNoiseRange;

	UPROPERTY()
	float ActivationNoiseLoudness_DEPRECATED;

	UPROPERTY()
	float ImpactNoiseLoudness_DEPRECATED;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	FGameplayTagContainer ProhibitedTargetTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	bool bLeadPawnTargets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float DesiredThrowAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI", meta=(EditCondition="bClampMaxYawAngleToFire"))
	float MaxYawAngleToFire;

	UPROPERTY()
	bool bClampMaxYawAngleToFire;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	bool bUseTargetActorLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Accuracy")
	float InitialAccuracyMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Accuracy")
	float InitialAccuracyMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Accuracy")
	float TargetAccuracyMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Accuracy")
	float TargetAccuracyMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Accuracy")
	float MinAccuracyDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Accuracy")
	float MaxAccuracyDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Accuracy")
	float AccuracyDistanceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Accuracy")
	int32 NumUsesToReachTargetAccuracy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Accuracy")
	int32 UseCount;

	UPROPERTY(EditDefaultsOnly, Category="Behavior")
	TArray<FFortGameplayAbilityBehaviorDistanceData> GameplayAbilityBehaviorDistanceData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	FFortGameplayAbilityMontageInfo MontageInfo;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Mod")
	TArray<TObjectPtr<UFortGameplayAbilityMod>> ModList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AbilityWeapon")
	TObjectPtr<UFortWeaponItemDefinition> AbilityWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	FText Description;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Ability", meta=(DisplayName="OnAbilityRemoved"))
	FORTNITEGAME_API void K2_OnAbilityRemoved();

	UFUNCTION(BlueprintImplementableEvent, Category="Ability")
	FORTNITEGAME_API void OnAbilityInputPressed();

	UFUNCTION(BlueprintImplementableEvent, Category="Ability")
	FORTNITEGAME_API void OnAbilityInputReleased();

	UFUNCTION(BlueprintImplementableEvent, Category="ChargeUp")
	FORTNITEGAME_API void OnChargeStateChanged(EFortAbilityChargeState OldChargeState, EFortAbilityChargeState NewChargeState);

	UFUNCTION(BlueprintImplementableEvent, Category="ChargeUp")
	FORTNITEGAME_API void OnDischarge();

	UFUNCTION(BlueprintImplementableEvent, Category="ChargeUp")
	FORTNITEGAME_API void OnReachedMaxCharge();

	UFUNCTION(BlueprintImplementableEvent, Category="ChargeUp")
	FORTNITEGAME_API void OnReachedMinCharge();

	UFUNCTION(BlueprintImplementableEvent, Category="ChargeUp")
	FORTNITEGAME_API void OnReachedZeroCharge();

	UFUNCTION()
	FORTNITEGAME_API void OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	uint8 bAcceptTargetActorVehicleForCanHitTests : 1;

	UPROPERTY()
	FFortGameplayAbilityMontageInfo PreviousMontageInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Display")
	TObjectPtr<UTexture2D> SmallPreviewImageOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltips")
	TSubclassOf<UFortTooltip> Tooltip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltips")
	TObjectPtr<UFortTooltipDisplayStatsList> StatList;

	UPROPERTY(EditDefaultsOnly, Category="ActorTracking")
	FAbilityTrackedActorSettings ActorTrackingSettings;

	UPROPERTY(Transient)
	TSubclassOf<UFortCameraMode> CurrentAbilityCameraModeClass;

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTagContainer AnalyticsTags;

	UPROPERTY(EditDefaultsOnly, Category="Tags", meta=(DisplayName="Cancel Self on Tags Changed"))
	TArray<FFortGameplayAbilityTagChangedAction> TagChangedActions;

private:
	UFUNCTION(BlueprintPure, Category="Tooltips")
	FORTNITEGAME_API UFortTooltipDisplayStatsList* GetDisplayStats() const;

	UFUNCTION(BlueprintPure, Category="Tooltips")
	FORTNITEGAME_API TSubclassOf<UFortTooltip> GetTooltip(bool bSummaryTooltip = false) const;

	UPROPERTY(EditAnywhere, Category="Activation")
	bool bIsMobileToggle;

	UPROPERTY(EditAnywhere, Category="Activation")
	bool bActivateIfTagsAlreadyPresent;

	UPROPERTY(Transient)
	float ChargeStartTime;

	UPROPERTY(Transient)
	EFortAbilityChargeState ChargeState;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, MinimalAPI)
class UFortGameplayAbilityMod : public UObject
{
	GENERATED_BODY()

};

