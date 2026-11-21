// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortMatchmakingGameModeButton.generated.h"

class UCommonButtonLegacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMatchmakingGameModeButton : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortMatchmakingGameModeButton(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingGameModeButton", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> IconTextButton_Play;

};

