// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_PushToTalk.generated.h"

class UPaperSprite;

UCLASS()
class UFortMobileActionButtonBehavior_PushToTalk : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> VoiceActiveSprite;

};

