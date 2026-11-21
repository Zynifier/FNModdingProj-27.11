// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SidebarSocialTagListBase.generated.h"

class UFortSocialUser;
class USocialTagWidget;

UENUM()
enum class ESocialTagListHighlightPolicy : uint8
{
	All = 0,
	TagList = 1,
	LocalUser = 2,
	FullColor = 3,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class USidebarSocialTagListBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetSocialUser(UFortSocialUser* SocialUser);

protected:
	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(DisplayName="Tags Are Selectable"))
	bool bAreTagsSelectable;

private:
	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(DisplayName="Supports Multi Selection"))
	bool bTagsSupportMultiSelection;

	UPROPERTY(BlueprintReadOnly, Export, Category="SidebarSocialTagListBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USocialTagWidget> SidebarSocialTagWidget_1;

	UPROPERTY(BlueprintReadOnly, Export, Category="SidebarSocialTagListBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USocialTagWidget> SidebarSocialTagWidget_2;

	UPROPERTY(BlueprintReadOnly, Export, Category="SidebarSocialTagListBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USocialTagWidget> SidebarSocialTagWidget_3;

	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(DisplayName="Show Category Customization"))
	bool bShowCategoryCustomization;

};

