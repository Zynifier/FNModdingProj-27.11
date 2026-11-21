// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "Charms/Data/FortCharmsMappingData.h"
#include "FortCustomCharmTypeEnum.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FortWeaponCharmPreviewActor.generated.h"

class AFortPlayerCharm;
class UAthenaCharmItemDefinition;
class USkeletalMesh;
class USkeletalMeshComponent;

UCLASS(Abstract, BlueprintType)
class AFortWeaponCharmPreviewActor : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Emote")
	void PreviewCharm(const UAthenaCharmItemDefinition* Charm);

protected:
	UFUNCTION(BlueprintCallable)
	void ApplyCharmToSkelMesh(USkeletalMeshComponent* MeshComp);

	UFUNCTION(BlueprintCallable)
	void ClearCharm();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewSkeletalMeshLoaded(USkeletalMesh* LoadedMesh, const FCharmPreviewEntry& EntryInfo);

	UFUNCTION(BlueprintCallable, Category="Cosmetics")
	void SetActiveCharmSlot(int32 CharmSlotIn);

	UFUNCTION(BlueprintCallable)
	void StartLoadingNextPreviewActor(int32 SlotIndex);

	UPROPERTY(BlueprintReadOnly, Category="FortWeaponCharmPreviewActor")
	TObjectPtr<UAthenaCharmItemDefinition> MyCharm;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerCharm> MyCharmActor;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> WeaponAttachMeshComp;

	UPROPERTY()
	TEnumAsByte<EFortCustomCharmType::Type> CharmSlot;

private:
	UPROPERTY(Transient)
	FCharmPreviewEntry CurrentEntryInfo;

};

