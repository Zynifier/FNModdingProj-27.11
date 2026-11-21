// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "Styling/SlateBrush.h"
#include "FortReplaySpectatorPawnBase.generated.h"

class UFortSpectatorCameraComponent;

UCLASS(MinimalAPI, HideCategories=("Navigation"))
class AFortReplaySpectatorPawnBase : public ASpectatorPawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Pawn", meta=(EditInline="true"))
	TObjectPtr<UFortSpectatorCameraComponent> SpectatorCameraComponent;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush MiniMapIconBrush;

};

