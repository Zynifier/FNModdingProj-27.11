// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "SocialUserTreeView.generated.h"

class USocialActionMenu;
class USocialListUserEntryBase;

UCLASS(Abstract, meta=(EntryClass="SocialListEntryBase"))
class SOCIALUMG_API USocialUserListViewBase : public UListViewBase
{
	GENERATED_BODY()

public:
	USocialUserListViewBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditAnywhere, Category="ListEntries")
	float EntrySpacing;

};

UCLASS(BlueprintType, Blueprintable)
class SOCIALUMG_API USocialUserListView : public USocialUserListViewBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USocialActionMenu> ActiveActionMenu;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<TSubclassOf<USocialActionMenu>, TObjectPtr<USocialActionMenu>> CachedActionMenuPool;

};

UCLASS(BlueprintType, Blueprintable)
class SOCIALUMG_API USocialUserTreeView : public USocialUserListView
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UserEntries")
	TSubclassOf<USocialListUserEntryBase> UserEntryWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UserEntries")
	TSubclassOf<USocialListUserEntryBase> InviteEntryWidgetClass;

};

