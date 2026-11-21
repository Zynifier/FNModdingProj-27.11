// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraFramingTypes.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "FrontEnd/ItemPreview/StateTransitionController.h"
#include "FortItemPreviewActor.generated.h"

class UAthenaCosmeticAccountItem;
class UFortAccountItemDefinition;
class UFortItem;
class UMaterialInstance;
class UMaterialInterface;
class USceneComponent;

USTRUCT(BlueprintType)
struct FCharacterDisplaySettings
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CharacterDisplaySettings")
	TWeakObjectPtr<UFortAccountItemDefinition> PrimaryItem;

	UPROPERTY()
	TArray<UAthenaCosmeticAccountItem*> CosmeticItems;

	UPROPERTY()
	TArray<FFortCosmeticVariantPreview> ItemVariantPreviews;

	UPROPERTY()
	TObjectPtr<UFortItem> SourceItemInstance;

};

UCLASS(Abstract, MinimalAPI, NotBlueprintable)
class AFortItemPreviewActor : public AActor, public IFortUICameraPositionTargetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	virtual bool ArePreviewVisualsReady() const;

	UFUNCTION(BlueprintPure)
	const UFortAccountItemDefinition* GetItemDefinition() const;

	UFUNCTION(BlueprintPure)
	const UFortItem* GetSourceItemInstance() const;

	UFUNCTION(BlueprintPure)
	static float GetStreamingSafetyDuration();

	UFUNCTION(BlueprintPure)
	virtual bool GetUseIASItemPreviewLoadingEvents() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAllLODStreamingComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCurrentVisualsCleanedUp();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetFloorMaterial(UMaterialInterface* InMaterialInstance);

protected:
	UFUNCTION(BlueprintPure)
	virtual bool GetHideModifierFXUntilResInDissolveComplete() const;

	UFUNCTION(BlueprintPure)
	virtual bool GetUseCleanUpForIASItemPreviewFXDestruction() const;

	UFUNCTION(BlueprintPure)
	virtual bool GetUseOutroForIASLoadingEffects() const;

	UFUNCTION(BlueprintPure)
	bool IsSceneTransitioning() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemsPendingTransitionOut(const FStateTransitionControllerHandle& TransitionController);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewVisualsBeginLoading();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewVisualsSpawned(const bool bUseSecondaryTransitionEffects, const bool bShowFloor);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortItemPreviewActor", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<UMaterialInstance> SpecialEventMaterial;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemPreviewActor", meta=(AllowPrivateAccess))
	FCharacterDisplaySettings CurrentDisplayInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<USceneComponent> ItemPreviewRootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewActor", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<USceneComponent> UserRotationComponent;

	UPROPERTY(BlueprintReadWrite, Category="FortItemPreviewActor", meta=(AllowPrivateAccess="TRUE"))
	float ZoomLevel;

	UPROPERTY(BlueprintReadWrite, Category="FortItemPreviewActor", meta=(AllowPrivateAccess="TRUE"))
	FRotator PedestalRotationOffset;

};

