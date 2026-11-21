// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ViewModels/Social/FortSocialUserViewModel.h"
#include "FortOnlineStatusViewModel.generated.h"

UENUM(BlueprintType)
enum class EPresenceIndicatorState : uint8
{
	Online = 0,
	Away = 1,
	Offline = 2,
	Blocked = 3,
};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick, DisplayName="Fort OnlineStatus Viewmodel"))
class FORTNITEUI_API UFortOnlineStatusViewModel : public UFortSocialUserViewModel
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortOnlineStatusViewModel")
	EPresenceIndicatorState OnlineStatus;

	UPROPERTY(BlueprintReadOnly, Category="FortOnlineStatusViewModel")
	bool bHideStatus;

};

