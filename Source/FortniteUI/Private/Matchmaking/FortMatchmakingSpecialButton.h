// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortMatchmakingSpecialButton.generated.h"

class UFortMatchmakingGameModeButton;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMatchmakingSpecialButton : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortMatchmakingSpecialButton(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingSpecialButton", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortMatchmakingGameModeButton> Button_LimitedTimeGameMode;

};

