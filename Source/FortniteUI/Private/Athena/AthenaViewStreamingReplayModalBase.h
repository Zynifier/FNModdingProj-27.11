// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaViewStreamingReplayModalBase.generated.h"

class UEditableText;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaViewStreamingReplayModalBase : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool IsValidGameSessionId(const FString& GameSessionId) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void PlayStreamingDSSReplay(const FString& GameSessionId) const;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaViewStreamingReplayModalBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_SessionSearch;

};

