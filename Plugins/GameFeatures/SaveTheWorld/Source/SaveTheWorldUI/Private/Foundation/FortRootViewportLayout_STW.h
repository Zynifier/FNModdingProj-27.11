// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortRootViewportLayout.h"
#include "FortRootViewportLayout_STW.generated.h"

class UTalkingHead;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortRootViewportLayout_STW : public UFortRootViewportLayout
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTalkingHead> TalkingHead;

};

