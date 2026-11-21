// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "FortFXStaticMeshComponent.generated.h"

class UStaticMeshComponent;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Object", "Activation", "Components|Activation", "Trigger"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortFXStaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetSource(UStaticMeshComponent* InMeshComponent);

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
	UPROPERTY(BlueprintReadOnly, Export, Category="FortFXStaticMeshComponent", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> SourceMeshComponent;

};

