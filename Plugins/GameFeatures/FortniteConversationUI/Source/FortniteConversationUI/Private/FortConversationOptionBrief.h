// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "ConversationContext.h"
#include "ConversationTypes.h"
#include "FortConversationOptionBrief.generated.h"

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortConversationOptionBrief : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="FortConversation", meta=(DisplayName="OnConfigure"))
	void ConfigureBP(const FConversationContext& ClientContext, const FClientConversationOptionEntry& OptionEntry, const int32 SelectedIndex);

};

