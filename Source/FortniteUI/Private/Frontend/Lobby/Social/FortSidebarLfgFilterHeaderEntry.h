// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialUserListHeaderEntry.h"
#include "FortSidebarLfgFilterHeaderEntry.generated.h"

class UCommonActionWidget;

UCLASS(meta=(DisableNativeTick))
class UFortSidebarLfgFilterHeaderEntry : public USocialUserListHeaderEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetFocusedInputDisplay(const bool bIsShown);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarLfgFilterHeaderEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> FocusedInputActionWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarLfgFilterHeaderEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> UnfocusedInputActionWidget;

};

