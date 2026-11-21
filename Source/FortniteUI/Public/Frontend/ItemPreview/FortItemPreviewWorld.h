// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Items/ItemPreviewTypes.h"
#include "FortItemPreviewWorld.generated.h"

class AFortItemPreviewSceneChanger;
class AFortStaticMeshActor;
class UChildActorComponent;
class UMaterialInstance;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UTexture2D;
enum class EBackgroundIntensityLevel : uint8;

UCLASS(Abstract)
class AFortItemPreviewWorld : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnIntensityChange(bool bToLowIntensity);

	UFUNCTION(BlueprintImplementableEvent)
	void OnResetIntensityChange(bool bFromLowIntensity);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInitialBackgroundTransition();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewSceneBackgroundChildActor(AFortStaticMeshActor* NewActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupMaterialBackground(const UMaterialInterface* LoadedBackgroundMaterial, const FVaultWorldBackgroundData& BackgroundInfo);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupTextureBackground(const UTexture2D* LoadedBackgroundTexture, const FVaultWorldBackgroundData& BackgroundInfo);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTransitionBackground(bool bPlayForward, EBackgroundIntensityLevel IntensityTransition);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTransitionItemDetails(const bool bShowItemDetails);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateDisplay(bool bShowFloor, bool bShowEffects);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateMaterialIndex(int32 MaterialIndex);

	UFUNCTION(BlueprintCallable)
	void SetBackgroundMaterialDynamic(UMaterialInstanceDynamic* InBackgroundMaterialDynamic);

	UFUNCTION(BlueprintCallable)
	void SetFloorMaterialDynamic(UMaterialInstanceDynamic* InFloorMaterialDynamic);

private:
	UPROPERTY(EditAnywhere, Category="FortItemPreviewWorld", meta=(AllowPrivateAccess="TRUE", Categories="UI.ItemPreview.SceneChanger"))
	FGameplayTag PreviewSceneChangerTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemPreviewWorld", meta=(AllowPrivateAccess))
	TObjectPtr<UMaterialInstance> BackgroundMaterial;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemPreviewWorld", meta=(AllowPrivateAccess))
	TObjectPtr<UMaterialInstanceDynamic> BackgroundMaterialDynamic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemPreviewWorld", meta=(AllowPrivateAccess))
	TObjectPtr<UMaterialInstance> FloorMaterial;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemPreviewWorld", meta=(AllowPrivateAccess))
	TObjectPtr<UMaterialInstanceDynamic> FloorMaterialDynamic;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Export, Category="FortItemPreviewWorld", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UChildActorComponent> SceneBackgroundComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortStaticMeshActor> SceneBackground;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Export, Category="FortItemPreviewWorld", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UChildActorComponent> SceneChangerComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortItemPreviewSceneChanger> PreviewSceneChanger;

	UPROPERTY(Transient)
	FVaultWorldBackgroundData CachedBackgroundData;

};

