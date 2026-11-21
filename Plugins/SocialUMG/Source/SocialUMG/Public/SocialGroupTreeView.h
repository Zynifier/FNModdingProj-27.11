// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/TreeView.h"
#include "SocialGroupTreeView.generated.h"

class USocialGroupListEntry;
class USocialInteractionMenu;
class USocialListUserEntryBase;

UCLASS()
class SOCIALUMG_API USocialGroupTreeView : public UTreeView
{
	GENERATED_BODY()

public:
	USocialGroupTreeView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UserEntries")
	TSubclassOf<USocialGroupListEntry> GroupEntryWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UserEntries")
	TSubclassOf<USocialListUserEntryBase> UserEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<USocialInteractionMenu> ActionMenuClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USocialInteractionMenu> ActionMenu;

};

