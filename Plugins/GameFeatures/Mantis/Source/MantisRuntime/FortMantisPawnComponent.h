// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnComponent.h"
#include "FortMantisData.h"
#include "FortMantisTypes.h"
#include "FortMantisPawnComponent.generated.h"

class AActor;
class AFortWeapon;
class UAnimMontage;
class UCharacterMovementComponent;
class UFortMantisData;
enum class EFortMantisBranchPath : uint8;
enum class EFortMantisBranchRule : uint8;
enum class EFortMantisTechniqueActivationInputType : uint8;
enum class EFortMantisTechniqueActivationTimingType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMantisTechniqueMetadataReadyEvent, const FFortMantisTechniqueMetadata&, TechniqueMetadata);

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class MANTISRUNTIME_API UFortMantisPawnComponent : public UPawnComponent
{
	GENERATED_BODY()

public:
	UFortMantisPawnComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure, Category="Mantis")
	const FFortMantisTechniqueMetadata& GetCurrentTechniqueMetadata() const;

	UFUNCTION(BlueprintPure)
	AActor* GetLockOnTarget() const;

	UFUNCTION(BlueprintPure, Category="Mantis")
	const UAnimMontage* GetMontageForCurrentTechnique() const;

	UFUNCTION(BlueprintPure, Category="Mantis")
	bool HasCurrentTechniqueMetadataBeenSet() const;

	UFUNCTION(BlueprintPure)
	bool HasLockOnTarget() const;

	UFUNCTION(BlueprintPure)
	bool IsPerformingLockOn() const;

	UFUNCTION(BlueprintPure, Category="Mantis")
	bool IsSpecificInputPressed(EFortMantisTechniqueActivationInputType InputType);

	UFUNCTION(BlueprintCallable)
	void SetLockOnState(bool bEnabled, AActor* TargetActor = nullptr);

	UFUNCTION(BlueprintCallable, Category="Mantis")
	void SimulateInputEvent(EFortMantisTechniqueActivationInputType InputType, EFortMantisTechniqueActivationTimingType InputTiming, const bool bForceProcessEvent = false);

	UFUNCTION(BlueprintCallable, Category="Mantis")
	bool TryManuallyEndCurrentTechnique();

	UFUNCTION(BlueprintCallable, Category="Mantis")
	bool TryManuallyStartTechnique(const int32 TechniqueDataIndex);

	UPROPERTY(BlueprintAssignable, Category="Mantis")
	FOnMantisTechniqueMetadataReadyEvent OnTechniqueMetadataReady;

protected:
	UFUNCTION()
	void OnCharacterMovementPreUpdate(UCharacterMovementComponent* CharMoveComp, float DeltaSeconds);

	UFUNCTION()
	void OnOwnerWeaponHolstered();

	UFUNCTION()
	void OnPostPhysicsRotation(UCharacterMovementComponent* CharMoveComp, float DeltaSeconds);

	UFUNCTION(BlueprintCallable, Category="Mantis")
	void SetBranchRule(EFortMantisBranchRule InBranchRule, EFortMantisBranchPath InBranchPath);

	UPROPERTY()
	TMap<TObjectPtr<UAnimMontage>, FFortMantisMontageData> MontageDataMap;

	UPROPERTY()
	TObjectPtr<UFortMantisData> MantisData;

	UPROPERTY()
	TObjectPtr<AFortWeapon> Weapon;

};

