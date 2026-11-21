// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "FortFXSkeletonMeshComponent.generated.h"

class USkeletalMeshComponent;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Object", "Mesh|SkeletalAsset", "Object", "Mobility", "Trigger"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortFXSkeletonMeshComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetSource(USkeletalMeshComponent* InMeshComponent);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effects")
	float AwakenFadeInTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effects")
	float AwakenDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effects")
	float AwakenFadeOutTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effects")
	float BuildingHitFadeInTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effects")
	float BuildingHitDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effects")
	float BuildingHitFadeOutTime;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortFXSkeletonMeshComponent", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SourceMeshComponent;

};

