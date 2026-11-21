// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortContentManagementList.h"

UFortContentManagementLabelWidget::UFortContentManagementLabelWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortContentManagementList::CanRequestNextUnlockPage() const
{
	return false;
}

void UFortContentManagementList::RequestNextUnlockPage()
{
}

void UFortContentManagementList::ResetUnlockList()
{
}

UFortContentManagementListView::UFortContentManagementListView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
