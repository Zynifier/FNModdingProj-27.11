// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCustomMatchmakingKeyModal.generated.h"

class UEditableText;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCustomMatchmakingKeyModal : public UFortActivatablePanel
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCustomMatchmakingKeyModal", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_MatchmakingKey;

};

