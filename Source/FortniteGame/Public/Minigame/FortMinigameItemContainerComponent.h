// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "FortEditorPreviewInterface.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortMinigameItemContainerComponent.generated.h"

UCLASS(Abstract, MinimalAPI)
class UFortMinigameItemContainerComponent : public UActorComponent, public ILevelSaveSpawnable, public IGameplayTagAssetInterface, public IEditorPreviewInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Item Data")
	bool bHideInActorDetails;

	FORTNITEGAME_API virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Events", meta=(DisplayName="Notify Item Container Changed"))
	FORTNITEGAME_API void K2_NotifyItemContainerChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="EditorPreview", meta=(DisplayName="Setup For Editor Preview"))
	FORTNITEGAME_API void K2_SetupForEditorPreview();

	UFUNCTION(BlueprintImplementableEvent, Category="EditorPreview", meta=(DisplayName="Update Editor Preview"))
	FORTNITEGAME_API void K2_UpdateEditorPreview(bool bHasMoved);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMinigameItemContainerComponent")
	FGameplayTagContainer EmptyFilterTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMinigameItemContainerComponent")
	FGameplayTagContainer NonEmptyFilterTags;

};

