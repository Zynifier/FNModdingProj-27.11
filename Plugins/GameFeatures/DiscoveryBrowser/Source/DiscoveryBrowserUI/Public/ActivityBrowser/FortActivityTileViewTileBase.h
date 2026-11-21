// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonBase.h"
#include "FortActivityTileViewTileBase.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityTileViewTileBase : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

};

