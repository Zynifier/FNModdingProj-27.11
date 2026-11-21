// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorkerBoardBase.generated.h"

class UFortItem;
class UFortWorker;
class UStaticMeshComponent;

UCLASS(BlueprintType)
class AWorkerBoardBase : public AActor
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleIconDefinitionsLoaded();

	UFUNCTION()
	void HandlePreviewImagesLoaded();

	UFUNCTION(BlueprintCallable)
	void SetupWorkerPortraits(const TArray<UStaticMeshComponent*> InWorkerPortraitComponents, const TArray<UFortItem*> InWorkerItems);

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> WorkerPortraitComponents;

	UPROPERTY()
	TArray<TObjectPtr<UFortWorker>> WorkerItems;

};

