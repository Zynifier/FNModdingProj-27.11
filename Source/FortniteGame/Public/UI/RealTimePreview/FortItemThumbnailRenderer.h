// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/RealTimePreview/FortThumbnailRenderer.h"
#include "FortItemThumbnailRenderer.generated.h"

class AFortItemCaptureActor;
class UFortItemDefinition;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Abstract, MinimalAPI)
class UFortItemThumbnailRenderer : public UFortThumbnailRenderer
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UMaterialInstanceDynamic* GetItemPreviewMaterial();

	UFUNCTION(BlueprintCallable, meta=(DeterminesOutputType="ThumbnailCaptureTarget"))
	AFortItemCaptureActor* GetOrCreateCaptureActor(TSubclassOf<AFortItemCaptureActor> ThumbnailCaptureTarget);

	UFUNCTION(BlueprintCallable)
	void InvalidateCapture();

	UFUNCTION(BlueprintCallable)
	void SetItemDefinition(UFortItemDefinition* InItemDefinition);

	UFUNCTION(BlueprintCallable)
	void UpdateItemCapture();

private:
	UPROPERTY(EditDefaultsOnly, Category="FortItemThumbnailRenderer")
	TObjectPtr<UMaterialInterface> PreviewMaterial;

	UPROPERTY(EditDefaultsOnly, Category="FortItemThumbnailRenderer")
	TSubclassOf<AFortItemCaptureActor> CaptureEnvironmentActorClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> PreviewMaterialInstance;

};

