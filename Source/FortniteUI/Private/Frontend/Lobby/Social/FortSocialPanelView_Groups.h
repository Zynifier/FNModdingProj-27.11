// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortSocialPanelView_Groups.generated.h"

class USocialGroupTreeView;

UCLASS()
class UFortSocialPanelView_Groups : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortSocialPanelView_Groups(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USocialGroupTreeView> TreeView_Groups;

};

