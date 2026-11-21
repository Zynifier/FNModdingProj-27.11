// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "Weapons/Data/FortItemWrapMappingData.h"
#include "FortItemWrapPreviewActor.generated.h"

class ACustomItemWrapModifier;
class UAnimationAsset;
class UAthenaItemWrapDefinition;
class UObject;
class USkeletalMesh;
class USkeletalMeshComponent;

UCLASS(Abstract, BlueprintType)
class AFortItemWrapPreviewActor : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Emote")
	void PreviewItemWrap(const UAthenaItemWrapDefinition* ItemWrap);

protected:
	UFUNCTION(BlueprintCallable)
	void ApplyWrapToSkelMesh(USkeletalMeshComponent* MeshComp);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewSkeletalMeshLoaded(USkeletalMesh* LoadedMesh, UAnimationAsset* LoadedAnimationAsset, UClass* LoadedAnimInstanceClass, const FItemWrapPreviewEntry& EntryInfo);

	UFUNCTION(BlueprintCallable)
	void StartLoadingNextPreviewActor(int32 SlotIndex);

	UPROPERTY(BlueprintReadOnly, Category="FortItemWrapPreviewActor")
	TObjectPtr<UAthenaItemWrapDefinition> MyWrap;

	UPROPERTY(BlueprintReadOnly, Category="FortItemWrapPreviewActor")
	TObjectPtr<ACustomItemWrapModifier> ItemWrapModifier;

private:
	UPROPERTY(Transient)
	FItemWrapPreviewEntry CurrentEntryInfo;

};

