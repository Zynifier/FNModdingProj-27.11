// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonButtonBase.h"
#include "FortActivityBrowserTileBase.generated.h"

class UFortGameActivity;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityBrowserTileBase : public UCommonButtonBase, public IUserListEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UFortGameActivity> AssignedGameActivity;

};

