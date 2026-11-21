// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "SidebarListEmptyPanelButton.generated.h"

class UCommonTextBlock;

UCLASS()
class FORTNITEUI_API USidebarListEmptyPanelButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ButtonText;

};

