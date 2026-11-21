// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Athena/GameDataBR.h"
#include "Building/BuildingItemCollectorActor.h"
#include "Building/BuildingTypes.h"
#include "Building/FortAttachToActorInterface.h"
#include "FortRarityEnum.h"
#include "BuildingItemWeaponUpgradeActor.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortPlayerController;
class AFortWeapon;
class UFortResourceItemDefinition;
class UFortWeaponItemDefinition;
class UPrimitiveComponent;
class UWeaponUpgradeRequiredResources;

USTRUCT()
struct FPlayerWeaponUpgradeHoldData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> InteractingPC;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortWeapon> UpgradeTargetWeapon;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingItemWeaponUpgradeActor : public ABuildingItemCollectorActor, public IFortAttachToActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Interaction")
	void BlueprintOnInteractInterrupted();

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_AllowSecondInteraction, Category="Interaction")
	bool bAllowSecondInteraction;

protected:
	UFUNCTION()
	void FloorDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnRep_AllowSecondInteraction();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	TObjectPtr<UFortResourceItemDefinition> WoodItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	TObjectPtr<UFortResourceItemDefinition> MetalItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	TObjectPtr<UFortResourceItemDefinition> BrickItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FScalableFloat WoodCostCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FScalableFloat MetalCostCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FScalableFloat BrickCostCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FScalableFloat HorizontalWoodCostCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FScalableFloat HorizontalMetalCostCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FScalableFloat HorizontalBrickCostCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Strings")
	FText WeaponCannotBeUpgradedText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Strings")
	FText NotEnoughRessourcesText;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BuildingItemWeaponUpgradeActor")
	EFortWeaponUpgradeInteractionResult UpgradeInteractionResult;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BuildingItemWeaponUpgradeActor")
	EFortWeaponUpgradeInteractionResult HorizontalUpgradeInteractionResult;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BuildingItemWeaponUpgradeActor")
	TObjectPtr<UWeaponUpgradeRequiredResources> RequiredResources;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BuildingItemWeaponUpgradeActor")
	TObjectPtr<UWeaponUpgradeRequiredResources> RequiredHorizontalResources;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BuildingItemWeaponUpgradeActor")
	TObjectPtr<UFortWeaponItemDefinition> CurrentWeaponDefinition;

	UPROPERTY(Transient)
	TArray<FPlayerWeaponUpgradeHoldData> PlayerToUpgradeWeaponData;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Interact Methods")
	EFortRarity UpgradedWeaponRarity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interaction")
	FScalableFloat InteractionTimeUncommon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interaction")
	FScalableFloat InteractionTimeRare;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interaction")
	FScalableFloat InteractionTimeVeryRare;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interaction")
	FScalableFloat InteractionTimeSuperRare;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interaction")
	FScalableFloat InteractionTimeMythic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attachment")
	TEnumAsByte<EBuildingAttachmentType> BuildingAttachmentType;

	UPROPERTY()
	bool bBlocksAttachmentPlacement;

private:
	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> BuildingActorAttachedTo;

};

UCLASS(BlueprintType)
class UWeaponUpgradeRequiredResources : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WeaponUpgradeRequiredResources")
	int32 RequiredWood;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WeaponUpgradeRequiredResources")
	int32 RequiredMetal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WeaponUpgradeRequiredResources")
	int32 RequiredBrick;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WeaponUpgradeRequiredResources")
	EFortWeaponUpgradeDirection Direction;

};

