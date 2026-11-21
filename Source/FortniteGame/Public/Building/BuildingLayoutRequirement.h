// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingPlayerPrimitivePreview.h"
#include "Building/BuildingTypes.h"
#include "BuildingLayoutRequirement.generated.h"

class AActor;
class ABuildingLayoutRequirement;
class ABuildingSMActor;
class AController;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UPrimitiveComponent;

UENUM(BlueprintType)
enum class ELayoutRequirementStatus : uint8
{
	Inactive_Invisible = 0,
	Active_Invisible = 1,
	Active_Visible = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLayoutSatisfied, ABuildingLayoutRequirement*, LayoutRequirement, const ABuildingSMActor*, SatisfyingBuildingSMActor);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class ABuildingLayoutRequirement : public ABuildingPlayerPrimitivePreview
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	void ActivateRequirement(bool bMakeVisible);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	void DeactivateRequirement();

	UFUNCTION()
	virtual void OnRequirementSatisfyingActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	void SetRequiredResourceType(EFortResourceType::Type DesiredResourceType);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	void SetRequirementVisible(bool bVisible);

	UFUNCTION(BlueprintPure, Category="Building")
	bool SupportsEditingOfOccupant() const;

	UPROPERTY(BlueprintAssignable)
	FOnLayoutSatisfied OnLayoutSatisfied;

	UPROPERTY(BlueprintAssignable)
	FOnLayoutSatisfied OnLayoutUnSatisfied;

protected:
	UFUNCTION()
	virtual void OnRep_RequirementStatus();

	UPROPERTY(EditAnywhere, SaveGame, Category="LayoutRequirement", meta=(DisplayName="BuildingClass"))
	TSubclassOf<ABuildingSMActor> LayoutRequirementSMActorClass;

	UPROPERTY(EditAnywhere, SaveGame, Category="LayoutRequirement")
	bool bIgnoreResourceTypeRequirements;

	UPROPERTY(EditAnywhere, SaveGame, Category="LayoutRequirement")
	bool bMakeSatisfyingActorIndestructibleWhileRequirementExists;

	UPROPERTY(Transient)
	bool bNeedToInitializeRequirementStatus;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_RequirementStatus)
	bool bRequirementSatisfied;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_RequirementStatus)
	ELayoutRequirementStatus RequirementStatus;

	UPROPERTY(EditAnywhere, SaveGame, Category="LayoutRequirement")
	TEnumAsByte<EFortResourceType::Type> OverrideResourceType;

	UPROPERTY(EditAnywhere, SaveGame, Category="LayoutRequirement")
	bool bAllowAnyPattern;

	UPROPERTY(EditAnywhere, SaveGame, Category="LayoutRequirement")
	bool bAllowOccupantPatternEditing;

	UPROPERTY(EditDefaultsOnly, SaveGame, Category="LayoutRequirement")
	TSoftObjectPtr<UMaterialInterface> LayoutDisplayMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> LayoutDisplayMID;

};

