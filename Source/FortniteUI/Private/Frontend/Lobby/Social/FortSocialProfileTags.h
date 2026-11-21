// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSocialProfilePanel.h"
#include "FortSocialProfileTags.generated.h"

class USidebarSocialTagListEditable;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialProfileTags : public UFortSocialProfileSubPanel
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(AllowPrivateAccess, DisplayName="Can Show Add Button and Can Select Tag"))
	bool bAllowEditing;

	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(AllowPrivateAccess, DisplayName="Show Adding in a SocialTag when Selected"))
	bool bShowAddingWidgetInSocialTagWhenSelected;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialProfileTags", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USidebarSocialTagListEditable> SidebarSocialTagList;

};

