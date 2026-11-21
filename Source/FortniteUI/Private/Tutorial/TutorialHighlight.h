// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "UI/Tutorial/HighlightInterface.h"
#include "TutorialHighlight.generated.h"

class UUserWidget;

UCLASS()
class UTutorialHighlight : public UWidget, public IHighlightInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Custom Tutorial Highlight")
	TSoftClassPtr<UUserWidget> CustomHighlightWidget;

};

