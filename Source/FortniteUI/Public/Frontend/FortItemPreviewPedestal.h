// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/FortItemPlacementActor.h"
#include "ModuleBoundary/FortPlayerControllerContext.h"
#include "FortItemPreviewPedestal.generated.h"

class APlayerController;
class UChildActorComponent;
class UCustomCharacterPart;
class UFortHero;
class UFortItem;
class UFortItemDefinition;
class USceneComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;

UCLASS()
class AFortItemPreviewPedestal : public AFortItemPlacementActor, public IFortPlayerControllerContext
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Preview Item"))
	void ClearDisplay();

	UFUNCTION(BlueprintCallable, meta=(DisplayName="Display Campaign NPC"))
	void PreviewItemBP(UFortItem* Item);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortItemPreviewPedestal")
	TObjectPtr<UFortItemDefinition> EditorTimeItemDefinitionToPreview;
#endif

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortItemPreviewPedestal")
	TWeakObjectPtr<APlayerController> ContextualPlayerController;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortHero> TemporaryHeroInstance;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UCustomCharacterPart>> AdditionalCharacterParts;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewPedestal", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<USceneComponent> WeaponPlacementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewPedestal", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UChildActorComponent> PreviewActorComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewPedestal", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> PreviewStaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewPedestal", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> PreviewSkelMeshComponent;

};

