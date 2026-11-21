// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortHexMapMarkerBase.generated.h"

class UAnimationAsset;
class UMaterialInstanceDynamic;
class USkeletalMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Actor", "Advanced", "Navigation", "mesh"))
class AFortHexMapMarkerBase : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInstanceDynamic>> CurrentMIDs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Visual")
	TObjectPtr<UAnimationAsset> IdleAnimation;

private:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Export, Category="Visual", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkelMeshComponent;

};

