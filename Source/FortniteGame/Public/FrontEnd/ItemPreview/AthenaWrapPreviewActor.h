// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FrontEnd/ItemPreview/FortItemPreviewMultiAngleActor.h"
#include "AthenaWrapPreviewActor.generated.h"

class UAthenaItemWrapDefinition;
class UCameraComponent;
class USceneComponent;
enum class EWrapPreviewCamera : uint8;

UENUM(BlueprintType)
enum class EWrapPreviewCamera : uint8
{
	Weapon = 0,
	LargeWeapon = 1,
	Vehicle = 2,
};

UCLASS(Abstract)
class AAthenaWrapPreviewActor : public AFortItemPreviewMultiAngleActor, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	EWrapPreviewCamera GetActiveCamera() const;

	UFUNCTION(BlueprintPure)
	bool IsShowingVehicle() const;

	UFUNCTION(BlueprintCallable)
	void ShowNextPreviewMesh();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="AthenaWrapPreviewActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInWeaponCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="AthenaWrapPreviewActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutVehicleCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="AthenaWrapPreviewActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInVehicleCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="AthenaWrapPreviewActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutCampaignVehicleCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="AthenaWrapPreviewActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInCampaignVehicleCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="AthenaWrapPreviewActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutLargeWeaponCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="AthenaWrapPreviewActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInLargeWeaponCameraComponent;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="AthenaWrapPreviewActor", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<USceneComponent> PreviewSpawnPointComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AthenaWrapPreviewActor", meta=(AllowPrivateAccess))
	TObjectPtr<UAthenaItemWrapDefinition> ItemWrapDef;

};

