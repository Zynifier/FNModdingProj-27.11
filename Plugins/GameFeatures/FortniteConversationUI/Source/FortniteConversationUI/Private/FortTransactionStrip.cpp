// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortTransactionStrip.h"

UFortTransactionStrip::UFortTransactionStrip(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortTransactionStrip::HandleOnItemCountChanged(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, UFortItemDefinition* Definition, int32 Delta)
{
}
