// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/SidebarSocialTagListBase.h"
#include "SidebarSocialTagListEditable.generated.h"

class UCommonButtonBase;

UCLASS()
class USidebarSocialTagListEditable : public USidebarSocialTagListBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(AllowPrivateAccess, DisplayName="Show AddButton"))
	bool bShowAddButton;

	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(AllowPrivateAccess, DisplayName="Show Adding in a SocialTag when Selected"))
	bool bShowAddingWidgetInSocialTagWhenSelected;

	UPROPERTY(BlueprintReadOnly, Export, Category="SidebarSocialTagListEditable", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> AddButton;

};

