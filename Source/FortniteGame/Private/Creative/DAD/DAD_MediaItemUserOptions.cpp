// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/DAD/DAD_MediaItemUserOptions.h"

const TArray<FDAD_MediaItemUserOption>& UDAD_MediaItemUserOptions::GetMediaOptions() const
{
	static TArray<FDAD_MediaItemUserOption> Dummy;
	return Dummy;
}
