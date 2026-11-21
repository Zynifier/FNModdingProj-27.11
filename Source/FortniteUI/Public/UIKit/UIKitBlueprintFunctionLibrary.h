// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UIKitBlueprintFunctionLibrary.generated.h"

class UUserWidget;
class UWidgetAnimation;

UCLASS()
class UUIKitBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="User Interface|Animation")
	static void PlayAnimationDuringTime(UUserWidget* Widget, UWidgetAnimation* Animation, const float PlayTime, const bool bPlayForward = true);

};

