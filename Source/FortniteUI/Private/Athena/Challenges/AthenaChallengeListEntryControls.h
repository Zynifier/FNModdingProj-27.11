// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaChallengeListEntryControls.generated.h"

class UFortCTAButton;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaChallengeListEntryControls : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnViewPlaylistButtonClicked);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeListEntryControls", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_ViewPlaylist;

};

