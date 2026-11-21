// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortItemCaptureActor.generated.h"

class UFortItemDefinition;
class UFortItemThumbnailRenderer;

UCLASS()
class AFortItemCaptureActor : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupCapture(UFortItemThumbnailRenderer* InRenderer, UFortItemDefinition* InItemDefinition);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortItemCaptureActor")
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortItemCaptureActor")
	TWeakObjectPtr<UFortItemThumbnailRenderer> Renderer;

};

