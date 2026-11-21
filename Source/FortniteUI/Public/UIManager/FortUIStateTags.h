// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UITag.h"
#include "FortUIStateTags.generated.h"

USTRUCT(meta=(Categories="UI.State"))
struct FUIStateTag : public FUITag
{
	GENERATED_BODY()

};

USTRUCT(meta=(Categories="UI.State.Athena"))
struct FUIStateTag_Athena : public FUIStateTag
{
	GENERATED_BODY()

};

USTRUCT(meta=(Categories="UI.State.Startup"))
struct FUIStateTag_FortStartup : public FUIStateTag
{
	GENERATED_BODY()

};

USTRUCT(meta=(Categories="UI.State.STW"))
struct FUIStateTag_STW : public FUIStateTag
{
	GENERATED_BODY()

};

