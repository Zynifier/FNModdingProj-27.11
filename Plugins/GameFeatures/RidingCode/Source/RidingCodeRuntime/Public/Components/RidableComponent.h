// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Engine/DataTable.h"
#include "Engine/EngineTypes.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility.h"
#include "Athena/FortPlayerPawnAthena.h"
#include "Camera/FortCameraMode_ThirdPerson.h"
#include "FortCombatTypes.h"
#include "FortHolsterWeaponSourceInterface.h"
#include "RidableComponent.generated.h"

class AActor;
class UAnimInstance;
class UFortCameraMode_Riding;
class URidableComponent;
class URiderComponent;
class USceneComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRidable_RiderChanged, URidableComponent*, Ridable, URiderComponent*, Rider);

USTRUCT()
struct FPrimaryFireAnimMontageAnimCoreTypeOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PrimaryFireAnimMontageAnimCoreTypeOverride")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> CoreTypeToOverride;

	UPROPERTY(EditDefaultsOnly, Category="PrimaryFireAnimMontageAnimCoreTypeOverride")
	FFortGameplayAbilityMontageInfo OverridingMontageInfo;

};

USTRUCT()
struct FPrimaryFireAnimMontageTagOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PrimaryFireAnimMontageTagOverride")
	FGameplayTag TagOverride;

	UPROPERTY(EditDefaultsOnly, Category="PrimaryFireAnimMontageTagOverride")
	FFortGameplayAbilityMontageInfo OverridingMontageInfo;

};

USTRUCT(BlueprintType)
struct FRidingAttachmentBoundsOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RidingAttachmentBoundsOverride")
	bool bUseOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RidingAttachmentBoundsOverride")
	FVector AttachSoftBounds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RidingAttachmentBoundsOverride")
	FVector AttachHardBounds;

};

USTRUCT(BlueprintType)
struct FRidingPettingData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RidingPettingData")
	bool bIsPettableCreature;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RidingPettingData")
	FFortGameplayAbilityMontageInfo RiderMalePettingMontageInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RidingPettingData")
	FFortGameplayAbilityMontageInfo RiderFemalePettingMontageInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RidingPettingData")
	FFortGameplayAbilityMontageInfo RidablePettingMontageInfo;

};

USTRUCT()
struct FRidingPlaylistBlacklistTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="RidingPlaylistBlacklistTableRow")
	FGameplayTagContainer PlaylistTags;

};

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class RIDINGCODERUNTIME_API URidableComponent : public UGameFrameworkComponent, public IFortHolsterWeaponSourceInterface
{
	GENERATED_BODY()

public:
	URidableComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool CanBePet(URiderComponent* Rider) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, meta=(DisplayName="Can Be Ridden"))
	bool CanBeRiddenBP(URiderComponent* Rider) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool CanRiderPlayEmote(const URiderComponent* Rider) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void CheatSetStaminaPercent(const float StaminaPercent);

	UFUNCTION(BlueprintPure)
	const FRidingPettingData& GetPettingData() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	USceneComponent* GetRidingAttachComponent() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	void GetRidingCapsuleSize(const URiderComponent* Rider, float OriginalRadius, float OriginalHalfHeight, float& OutRadius, float& OutHalfHeight) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	void GetRidingEmoteCapsuleSize(const URiderComponent* Rider, float OriginalRadius, float OriginalHalfHeight, float& OutRadius, float& OutHalfHeight) const;

	UFUNCTION(BlueprintPure)
	bool IsBeingRidden() const;

	UFUNCTION(BlueprintPure)
	virtual bool IsFlying() const;

	UFUNCTION(BlueprintPure)
	bool IsSprinting() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool ShouldCameraFocusOnRidable(const URiderComponent* Rider) const;

	UPROPERTY(BlueprintAssignable)
	FOnRidable_RiderChanged OnRiderStartedRiding;

	UPROPERTY(BlueprintAssignable)
	FOnRidable_RiderChanged OnRiderStoppedRiding;

protected:
	UFUNCTION()
	void HandleRiderEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION(BlueprintNativeEvent)
	void HandleRiderStartedRiding(URiderComponent* Rider);

	UFUNCTION(BlueprintNativeEvent)
	void HandleRiderStoppedRiding(URiderComponent* Rider);

	UFUNCTION()
	void OnRep_ActiveRider();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Anim")
	TSubclassOf<UAnimInstance> RiderAnimLayerOverlayClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Attachment")
	FName AttachSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Attachment")
	FVector AttachLocationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Attachment")
	FRotator AttachRotationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Attachment")
	FName ClientAttachGuideSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Attachment")
	FVector ClientAttachGuideLocationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Ridable Prop")
	FName RidablePropAttachSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Ridable Prop")
	FVector RidablePropAttachLocationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Ridable Prop")
	FRotator RidablePropAttachRotationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Ridable Prop")
	float RidablePropAttachScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Ridable Prop")
	float RidablePropAttachRiderVerticalBuffer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop")
	FRidingAttachmentBoundsOverride RiderPropAttachBoundsOverride;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Rider Noise Generation")
	bool bOverrideNoiseGeneration;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Rider Noise Generation")
	FFortPlayerPawnAthenaMovementNoiseOverride RiderMovementNoiseOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Camera Overrides")
	TSubclassOf<UFortCameraMode_Riding> CameraModeClassOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Camera Overrides")
	TSubclassOf<UFortCameraMode_Riding> SprintCameraModeClassOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Camera Overrides")
	FScalableFloat UseTargetingAdditionalViewTargetSpaceViewOffsetOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Camera Overrides")
	FInterpOffset TargetingAdditionalViewTargetSpaceViewOffsetOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	FVector WeaponTargetingSourceOffsetModifier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding")
	FGameplayTag RidableTag;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding")
	FGameplayTag EnergyDepletedTag;

	UPROPERTY(EditDefaultsOnly, Category="Riding")
	FDataTableRowHandle PlaylistTagBlacklistRowHandle;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ActiveRider, Export, Category="Riding", meta=(EditInline="true"))
	TObjectPtr<URiderComponent> ActiveRider;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URiderComponent> LastRider;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Riding", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> RidableProp;

	UPROPERTY(Transient)
	float OriginalCapsuleRadius;

	UPROPERTY(Transient)
	float OriginalCapsuleHalfHeight;

	UPROPERTY(Transient)
	float RidingCapsuleRadius;

	UPROPERTY(Transient)
	float RidingCapsuleHalfHeight;

	UPROPERTY(Transient)
	bool bOriginalClientPositionSmoothingThrottlingSetting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	FScalableFloat MaxHalfAimingAngle;

	UPROPERTY(EditDefaultsOnly, Category="Riding|Anim")
	TArray<FPrimaryFireAnimMontageAnimCoreTypeOverride> PrimaryFireMontageAnimCoreTypeOverrides;

	UPROPERTY(EditDefaultsOnly, Category="Riding|Anim")
	TArray<FPrimaryFireAnimMontageTagOverride> PrimaryFireMontageTagOverrides;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Petting")
	FRidingPettingData PettingData;

	UPROPERTY(Transient)
	FTimerHandle RestoreCollisionHandle;

	UPROPERTY(BlueprintReadWrite, Category="Riding")
	bool bIsSprinting;

};

