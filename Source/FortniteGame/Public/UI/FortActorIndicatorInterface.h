// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortActorIndicatorInterface.generated.h"

class AActor;
class UCanvasPanel;
enum class EFortActorIndicatorContainerWidget : uint8;

UENUM(BlueprintType)
enum class EFortActorIndicatorContainerWidget : uint8
{
	Top = 0,
	Middle = 1,
	Bottom = 2,
};

UINTERFACE(MinimalAPI)
class UFortActorIndicatorInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortActorIndicatorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	UCanvasPanel* GetCanvasPanelContainer(EFortActorIndicatorContainerWidget ContainerEnum) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	AActor* GetIndicatedActor() const;

	UFUNCTION(BlueprintNativeEvent)
	float GetRemovalDuration();

	UFUNCTION(BlueprintNativeEvent)
	void NotifyWillBeRemoved();

};

